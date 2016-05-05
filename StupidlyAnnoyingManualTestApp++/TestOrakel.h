#pragma once

#include "stdafx.h"
#include "../RegualExpressions/RegularExpression.h"

/// <summary>	Simp fix. </summary>
///
/// <param name="r1">	[in,out] If non-null, the first RE. </param>
///
/// <returns>	null if it fails, else a pointer to a RE. </returns>
RE* simpFix(RE* r1);

/// <summary>	Tests closure transform. </summary>
///
/// <param name="r">	[in,out] If non-null, the RE to process. </param>
/// <param name="s">	The std::string to process. </param>
///
/// <returns>	true if the test passes, false if the test fails. </returns>
bool testClosureTransform(RE* r, std::string s);

/// <summary>
/// Ein Testfall besteht aus einem regulaeren Ausdruck (RE)
/// und einem Eingabestring.
/// 
/// Testorakel match ueberprueft ob string s enthalten in regex r.
/// 
/// Simplifizierer korrekt fuer Testfall, falls Testorakel gleiches Ergebnis liefert fuer
/// Original regex r und simplifizierten regex r->simp()
/// </summary>
///
/// <remarks>	Boris, 4/6/2016. </remarks>
///
/// <param name="r">	[in,out] If non-null, the RE to process. </param>
/// <param name="s">	The std::string to process. </param>
///
/// <returns>	true if the test passes, false if the test fails. </returns>
bool testSimp(RE* r, std::string s);