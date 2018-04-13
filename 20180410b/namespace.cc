 ///
 /// @file    namespace.cc
 /// @author  jcx(yxjcxstack@gmail.com)
 /// @date    2018-04-09 22:30:54
 ///
#include <stdio.h> 
#include <iostream>
using std::cout;
using std::endl;
namespace B
{
	//名称空间之中可以无限存放实体，可以多次出现
	void displayB();
}

namespace A
{
	//变量可以是函数 对象  都统称为namespace的实体
	int a=10;
	void displayA()
	{
		cout << "displayA()" << endl;
	
		B::displayB();	
	}
	namespace C
	{
		void displayC()
		{
			cout << "C::displayC()" << endl;
		}	
	}
}
namespace B
{
	int b=100;
	void displayB()
	{
		cout << "displayB()" << endl;
		A::C::displayC();
	}
}


int main()
{
	A::displayA();
	::printf("hello\n");
}

