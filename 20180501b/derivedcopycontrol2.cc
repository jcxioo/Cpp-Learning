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
		Base()
		: _pdata(new char [1]())
		{
			cout << "Base()" << endl;
		}
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
			delete [] _pdata;
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
//则执行派生类件的复制控制时，会自动调用基类相应的复制控制函数。/
//2、当派生类有显式定义复制控制函数时，基类也有显式定义复制控制函数，
//则执行派生类间的复制控制函数时，不会再自动调用基类相应的复制控制函数
//必须手动显式调用。
class Derived
:public Base
{
	public:
		Derived(const char * pdata,const char * pdata2)
		:Base(pdata)
		, _pdata2(new char[strlen(pdata2) + 1]())
		{
			strcpy(_pdata2, pdata2);
			cout << "Derived(const char *,const char *)" << endl; 			
		}

		Derived(const Derived & rhs)
		: Base(rhs)//显式调用基类的构造函数
		, _pdata2(new char[strlen(rhs._pdata2)]())
		{
			strcpy(_pdata2, rhs._pdata2);
			cout << "Derivecd(const Derived)" << endl;
		}
		
		~Derived()
		{
			cout << "~Derived()" << endl;
			delete [] _pdata2;
		}

		friend std::ostream & operator << (std::ostream & os, const Derived & rhs);
	private:
		char * _pdata2;
};

std::ostream & operator << (std::ostream & os, const Derived & rhs)
{
	os << (Base&)rhs << " "
		<< rhs._pdata2;
	return os;
}

int main(void)
{
	Derived d1("hello","world");
	Derived d2(d1); //派生类中没有显示的复制构造函数时会自动调用基类的复制构造函数
	
	cout << "d1 = " << d1 << endl << endl;;
	cout << "d2 = " << d2 << endl;
	Derived d3("xixi","haha");
	d2 = d3;
	cout << "d3 = " << d3 << endl;
	cout << "d4 =  " << d2 << endl; 
	return 0;
}
