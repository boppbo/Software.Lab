// StupidlyAnnoyingManualTestApp++.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../CustomStrings/CustomStrings.h"
#include "../RegualExpressions/Alternative.h"
#include "../RegualExpressions/Character.h"
#include "../RegualExpressions/Concatenation.h"
#include "../RegualExpressions/Phi.h"
#include "../RegualExpressions/Star.h"
#include "TestOrakel.h"

using namespace std;

void testString()
{
    String s1;
    String s2("Hello");
    String s3(s2);
    s1 += s2; s2 = s3;
    cout << s2 << endl;
    cout << s2[2] << endl;
}

void testRegex()
{
    // a + (a+b)
    RE* r1 = new Alt(
        new Ch('a'),
        new Alt(new Ch('a'), new Ch('b')));
    cout << r1->pretty() << endl;
    cout << r1->simp()->pretty() << endl;

    // (a+b) + a
    RE* r2 = new Alt(
        new Alt(new Ch('a'), new Ch('b')),
        new Ch('a'));
    cout << r2->pretty() << endl;
    cout << r2->simp()->pretty() << endl;

    // phi + c
    RE* r3 = new Alt(new Phi(), new Ch('c'));
    cout << r3->pretty() << endl;
    cout << r3->simp()->pretty() << endl;

    // c + phi
    RE* r4 = new Alt(new Ch('c'), new Phi());
    cout << r4->pretty() << endl;
    cout << r4->simp()->pretty() << endl;


    // c**
    RE* r5 = new Star(new Star(new Ch('c')));

    cout << r5->pretty() << endl;
    cout << r5->simp()->pretty() << endl;

    // phi*
    RE* r6 = new Star(new Phi());

    cout << r6->pretty() << endl;
    cout << r6->simp()->pretty() << endl;

    // (phi + c) + c**
    RE* r7 = new Alt(r3, r5);

    cout << r7->pretty() << endl;
    // exhaustively apply simplifications
    cout << simpFix(r7)->pretty() << endl;
}

void testFSA()
{
    // (ab)*
    RE * r1 = new Star(new Conc(new Ch('a'), new Ch('b')));

    testClosureTransform(r1, "abab");
    testClosureTransform(r1, "ababa");
}

int main()
{
    cout << "String tests:" << endl;
    testString();
    cout << endl;

    cout << "Regex tests:" << endl;
    testRegex();
    cout << endl;

    cout << "FSA tests:" << endl;
    testFSA();

    getchar();
    return 0;
}

