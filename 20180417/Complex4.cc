 ///
 /// @file    Complex4.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-04-17 10:03:58
 ///
 
#include "Mylogger.h"
#include <iostream>
using std::cout;
using std::endl;

class Complex
{
public:
	Complex(double dreal, double dimag)
	: _dreal(dreal)
	, _dimag(dimag)
	{
		LogDebug("Complex(double, double)");
	}
	void display() const
	{
		if(_dreal == 0 && _dimag != 0)
			cout << _dimag << "i" << endl;
		else
		{
			cout << _dreal;
			if(_dimag > 0)
				cout << "+" << _dimag << "i" << endl;
			else if(_dimag < 0)
				cout << _dimag << "i" << endl;
			else 
				cout << endl;
		}
	}

	//如果执行完操作之后，对象本身的值发生变化，建议以成员函数形式进行重载
	//
	// -= *=  /=   %=
	//
	Complex & operator+=(const Complex & rhs)
	{
		_dreal += rhs._dreal;
		_dimag += rhs._dimag;
		return *this;
	}

	//前置++, 其效率比后置更高
	Complex & operator++()
	{
		++_dreal;
		++_dimag;
		return *this;
	}
	//后置++
	Complex operator++(int) //int是为了区分前置和后置
	{
		Complex ret(*this);
		++_dreal;
		++_dimag;
		return ret;
	}

	friend Complex operator+(const Complex & lhs, const Complex & rhs);
	friend bool operator<(const Complex & lhs, const Complex & rhs);
private:
	double _dreal;
	double _dimag;
};

//以友元函数的形式重载运算符
//
//+ - * /
//
Complex operator+(const Complex & lhs, const Complex & rhs)
{
	return Complex(lhs._dreal + rhs._dreal,
				   lhs._dimag + rhs._dimag);
}

//自定义比较方式
//
//>  >= <=  !=  ==
//
bool operator<(const Complex & lhs, const Complex & rhs)
{
	return lhs._dreal < rhs._dreal;
}
 
//int operator+(int,int);

int main(void)
{
	int a = 3, b = 4;
	int c = a + b;
	cout << "c = " << c << endl;

	a += b;// a = a + b

	++a;
	a++;

	Complex c1(1, 2);
	cout << "c1 = ";
	c1.display();

	Complex c2(-3, 4);
	cout << "c2 = ";
	c2.display();

	Complex c3 = c1 + c2;
	cout << "c3 = ";
	c3.display();
	cout << endl;

	c1 += c2;
	cout << "c1 = ";
	c1.display();

	cout << "前置++，表达式的值:";
	(++c1).display();
	cout << endl;
	cout << "前置++ 之后, c1 =";
	c1.display();

	cout << "后置++，表达式的值:";
	(c1++).display();
	cout << "后置++ 之后, c1 =";
	c1.display();

	cout << "比较方式：" << endl;
	cout << "c1 < c2 ? " << (c1 < c2) << endl;
	return 0;
}
