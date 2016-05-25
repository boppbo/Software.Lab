// CustomStrings.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "CustomStrings.h"
#include <iostream>

/// <summary>
/// Performs application-defined tasks associated with freeing, releasing, or resetting unmanaged
/// resources.
/// </summary>
///
/// <remarks>	Boris, 4/4/2016. </remarks>
void String::dispose()
{
	if (this->charArr != "")
	{
		delete[] this->charArr;
		this->charArr = "";
		this->size = 0;
	}
}

void String::init(const char* charArr)
{
	this->size = this->len(charArr);
	if (this->size < 1)
		return;

	this->charArr = new char[this->size + 1];
	for (int i = 0; i <= this->size; i++)
	{
		this->charArr[i] = charArr[i];
	}
}

/// <summary>	strlen for poor people. </summary>
///
/// <remarks>	Boris, 4/4/2016. </remarks>
///
/// <param name="charArr">	[in,out] If non-null, array of characters. </param>
///
/// <returns>	An int. </returns>
int String::len(const char * charArr)
{
	int size = 0;
	
	if (charArr != nullptr)
		while (charArr[size] != '\0') size++;

	return size;
}

/// <summary>	Constructor. </summary>
///
/// <remarks>	Boris, 4/4/2016. </remarks>
///
/// <param name="value">	The value. </param>
String::String(char value)
{
	this->charArr = new char[2] {value, '\0'};
	this->size = 1;
}

/// <summary>	Constructor. </summary>
///
/// <remarks>	Boris, 4/4/2016. </remarks>
///
/// <param name="charArr">	Array of characters. </param>
String::String(const char* charArr)
{
	init(charArr);
}

/// <summary>	Destructor. </summary>
///
/// <remarks>	Boris, 4/4/2016. </remarks>
String::~String()
{
	this->dispose();
}

String& String::operator=(const String& other)
{
	this->dispose();
	this->init(other.charArr);
	return *this;
}

/// <summary>	Addition assignment operator. </summary>
///
/// <remarks>	Boris, 4/4/2016. </remarks>
///
/// <param name="other">	The other. </param>
///
/// <returns>	The result of the operation. </returns>
String& String::operator+=(const String& other)
{
	char* newArr = new char[this->size + other.size + 1];

	// copy self
	for (int i = 0; i < this->size; i++)
	{
		newArr[i] = this->charArr[i];
	}
	// copy other - includes the \0
	for (int i = 0; i <= other.size; i++)
	{
		newArr[this->size + i] = other.charArr[i];
	}

	this->dispose();
	this->init(newArr);

	return *this;
}

/// <summary>	Array indexer operator. </summary>
///
/// <remarks>	Boris, 4/4/2016. </remarks>
///
/// <param name="index">	Zero-based index of the string. </param>
///
/// <returns>	The indexed value. </returns>
char& String::operator[](int index) const
{
	return this->charArr[index];
}

/// <summary>	Stream insertion operator. </summary>
///
/// <remarks>	Boris, 4/4/2016. </remarks>
///
/// <param name="out">	[in,out] The out stream. </param>
/// <param name="s">  	[in,out] The String to process. </param>
///
/// <returns>	The out stream. </returns>
std::ostream& operator<<(std::ostream& out, String& s)
{
	for (int i = 0; i< s.size; i++) {
		out << s.charArr[i];
	}

	return out;
}