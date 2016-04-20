// StupidlyAnnoyingManualTestApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "../BitManipulation/switchLowHighByte.h"
#include "../BitManipulation/serialization.h"
#include "../RecognizePattern/breakIntoWords.h"
#include "../RecognizePattern/longestSuffix.h"
#include "../RecognizePattern/wordCount.h"
#include <string.h>

enum TestEnum {
	OK,
	FAIL
};
typedef enum TestEnum Test;

typedef struct {
	char* input;
	int expected;
} TestCase;

typedef struct {
	char* input;
	char* expected;
} TestCaseExtract;

Test testLowHigh(short int i)
{
	short int swapped = switchLowHighByte(i);
	
	if (swapped == i)
		return FAIL;

	swapped = switchLowHighByte(swapped);
	return i == swapped ? OK : FAIL;
}

Test testSD(Status s, Numbers n) {
	short int data;
	Status s2;
	Numbers n2;

	// Test execution
	serialize(s, n, &data);
	deserialize(data, &s2, &n2);

	return s2 == s && n2 == n ? OK : FAIL;
}

Test testCount(char* input, int expected) {
	return expected == count(input) ? OK : FAIL;
}

void runTests(int no, TestCase test[]) {
	Test t;
	int i;

	for (i = 0; i < no; i++) {
		printf("Test %d: ", i);
		t = testCount(test[i].input, test[i].expected);
		if (OK == t)
			printf("OK \n");
		if (FAIL == t)
			printf("FAIL \n");
	}
}
void runExTests(int no, TestCaseExtract test[])
{
	Test t;
	int i;

	for (i = 0; i < no; i++) {
		printf("Test %d: ", i);
		t = strcmp(extract(test[i].input), test[i].expected) == 0 ? OK : FAIL;

		if (OK == t)
			printf("OK \n");
		if (FAIL == t)
			printf("FAIL \n");
	}
}

int main()
{
	const int exTestCount = 3;
	TestCaseExtract exTests[3] =
	{
		{ "Ha::ll::o", "o" },
		{ "Ha::ll:::o", "o" },
		{ "47::11", "11" }
	};
	TestCase countTests[9] = {
		{ "", 0 },
		{ "Hallo", 1 },
		{ "  Hallo", 1 },
		{ "Hallo", 1 },
		{ "  Hallo  ", 1 },

		{ "Hal lo", 2 },
		{ " Hal lo", 2 },
		{ "Hal lo ", 2 },
		{ " Hal lo  ", 2 }
	};

	//First exercise
	if (testLowHigh(0x1234) != OK)
		printf("testLowHigh error!\n");
	if (testSD(Stop, Fifteen) != OK)
		printf("testSD error!\n");
	
	//Second exercise
	// extract tests
	runExTests(exTestCount, exTests);
	// count tests
	runTests(9, countTests);

	// break into words tests
	char* words[] = { NULL, NULL, NULL, NULL };
	char str[] = " Hal  lo We lt ";
	breakIntoWords(str, 3, words);
	if (strcmp(words[0], "Hal") != 0
		|| strcmp(words[1], "lo") != 0
		|| strcmp(words[2], "We") != 0
		|| words[3] != NULL)
		printf("breakIntoWords error!\n");

	// Wait for input
	getchar();
}

