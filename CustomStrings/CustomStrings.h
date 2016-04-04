// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the CUSTOMSTRINGS_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// CUSTOMSTRINGS_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef CUSTOMSTRINGS_EXPORTS
#define CUSTOMSTRINGS_API __declspec(dllexport)
#else
#define CUSTOMSTRINGS_API __declspec(dllimport)
#endif

#include <ostream>

/// <summary>	The string class. </summary>
///
/// <remarks>	Boris, 4/4/2016. </remarks>

class CUSTOMSTRINGS_API String {
private:
	char* charArr = "";
	int size = 0;
	void dispose();
	static int len(const char* charArr);
public:
	String() { };
	explicit String(char character);
	explicit String(const char* charArr);
	String(const String& other) : String(other.charArr) { }
	~String();

	char& operator[](int index) const;
	String& operator=(const String& other) const;
	String& operator+=(const String& other) const;

	CUSTOMSTRINGS_API friend std::ostream& operator<< (std::ostream &out, String &s);
};

