 ///
 /// @file    derivedcopycontrol.cc
 /// @author  jcx(yxjcxstack@gmail.com)
 /// @date    2018-05-01 18:59:29
 ///
 
#include <iostream>
#include <string.h>
using std::cout;
using std::endl;

class Base
{
	public:
		Base(const char * pdata)
		: _pdata(new char [strlen(pdata) + 1]())
		{
			strcpy(_pdata, pdata);
			cout << "Base(const char *)" << endl;
		}

		Base(const Base & rhs)
		: _pdata(new char[strlen(rhs._pdata) + 1]())
		{
			strcpy(_pdata, rhs._pdata);
			cout << "Base(const Base &)" << endl;
		}

		Base & operator = (const Base & rhs)
		{
			if (this != & rhs)
			{
				delete [] _pdata;
				_pdata = new char[strlen(rhs._pdata) + 1]();
				strcpy(_pdata, rhs._pdata);
				cout << "Base & operator = (const Base & rhs)" << endl;
			}
			return *this;
		}
		~Base()
		{
			cout << "~Base()"  << endl;
		}
		
		friend std::ostream & operator << (std::ostream & os, const Base & rhs);
	private:
		char * _pdata;
};

std::ostream & operator << (std::ostream & os, const Base & rhs) 
{
	os << rhs._pdata ;
	return os;
}
//派生类与派生类之间的复制控制：
//1、当派生类没有定义复制控制函数时，但基类有显式定义复制控制函数，
//则执行派生类件的复制控制时，会自动调用基类相应的复制控制函数。
 class Derived
:public Base
{
	public:
		Derived(const char * pdata)
		:Base(pdata)
		{
			cout << "Derived(const char *)" << endl; 			
		}
};

int main(void)
{
	Derived d1("hello");
	Derived d2(d1); //派生类中没有显示的复制构造函数时会自动调用基类的复制构造函数
	
	cout << "d1 = " << d1 << endl;
	cout << "d2 = " << d2 << endl;
	Derived d3("world");
	d2 = d3;
	cout << "d3 = " << d3 << endl;
	cout << "d4 =  " << d2 << endl; 
	return 0;
}
