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
	void init(const char* charArr);
	static int len(const char* charArr);
public:
	/// <summary>	Default constructor. </summary>
	String() { };

	/// <summary>	Constructor. </summary>
	///
	/// <param name="character">	The character. </param>
	explicit String(char character);

	/// <summary>	Constructor. </summary>
	///
	/// <param name="charArr">	Array of characters. </param>
	explicit String(const char* charArr);

	/// <summary>	Copy constructor. </summary>
	///
	/// <param name="other">	The other. </param>
	String(const String& other) : String(other.charArr) { }
	
	/// <summary>	Destructor. </summary>
	~String();

	/// <summary>	Array indexer operator. </summary>
	///
	/// <param name="index">	Zero-based index of the. </param>
	///
	/// <returns>	The indexed value. </returns>
	char& operator[](int index) const;

	/// <summary>	Assignment operator. </summary>
	///
	/// <param name="other">	The other. </param>
	///
	/// <returns>	A shallow copy of this object. </returns>
	String& operator=(const String& other);

	/// <summary>	Addition assignment operator. </summary>
	///
	/// <param name="other">	The other. </param>
	///
	/// <returns>	The result of the operation. </returns>
	String& operator+=(const String& other);

	/// <summary>	Stream insertion operator. </summary>
	///
	/// <param name="out">	[in,out] The out. </param>
	/// <param name="s">  	[in,out] The String to process. </param>
	///
	/// <returns>	The shifted result. </returns>
	CUSTOMSTRINGS_API friend std::ostream& operator<< (std::ostream &out, String &s);
};

