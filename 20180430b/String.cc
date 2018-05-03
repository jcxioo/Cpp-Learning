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
		//
		//复制构造函数的参数无法判断传递过来的实参是左值还是右值
		String(const String & rhs)
		: _pstr(new char [strlen(rhs._pstr +1)]())
		{
			strcpy(_pstr, rhs._pstr);
			cout << "String (const String &)" << endl;
		}
		//定义了移动构造函数和移动赋值运算符函数的类，称其为具有移动语义的类 
		
		//移动构造函数
		String(String && rhs) //右值引用的诞生就意味着修改
		: _pstr(rhs._pstr)
		{
			rhs._pstr = NULL;
			cout << "String(String &&)" << endl;
		}

		String & operator = (const String & rhs)
		{
			cout << "String & operator=(const String&)" << endl;
			if(this != & rhs)
			{
				delete [] _pstr;
				_pstr = new char[strlen(rhs._pstr) + 1]();
				strcpy(_pstr, rhs._pstr);
			}
			return * this;
		}
	
		String & operator = (String && rhs)
		{
			cout << "String & operator = (String &&)" << endl;
			if(this != & rhs)
			{
				delete [] _pstr;
				_pstr = rhs._pstr;
				rhs._pstr = NULL;
			}
			return * this;
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

