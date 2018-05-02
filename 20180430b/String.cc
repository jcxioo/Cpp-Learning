 ///
 /// @file    String.cc
 /// @author  jcx(yxjcxstack@gmail.com)
 /// @date    2018-04-30 03:39:07
 ///
 
#include <iostream>
#include <string.h>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class String
{
	public:
		String()
		: _pstr(new char [1]())
		{
			cout << "String()" << endl;
		}

		String(const char * pstr)
		: _pstr(new char[strlen(pstr)+1]())
		{
			strcpy(_pstr, pstr);
			cout << "String (const char * )" << endl;
		}

		String(const String & rhs)
		: _pstr(new char [strlen(rhs._pstr +1)]())
		{
			strcpy(_pstr, rhs._pstr);
			cout << "String (const String &)" << endl;
		}


	private:
		char * _pstr;
};

int main(void)
{
	vector<String> vecStr;
	vecStr.push_back("hello");
//	cout << "vecStr[0] = " << vecStr[0] << endl;
}

