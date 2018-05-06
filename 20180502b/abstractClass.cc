 ///
 /// @file    abstractClass.cc
 /// @author  jcx(yxjcxstack@gmail.com)
 /// @date    2018-05-03 21:19:17
 ///
 
#include <iostream>
using std::cout;
using std::endl;
//定义了protected的构造函数的类也成为了抽象类
class A
{
	public:
		void display() const
		{
			cout << "A::display()" << endl;
		}
	protected:
		A() 
		{	cout << "A()" << endl;}

};
class B
:public A
{
	public:
		B()
		{
			cout << "B()" << endl;
		}
};

int main(void)
{
//	A a;
	A * pa = new B;
	pa->display();
	return 0;
}
