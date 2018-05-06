 ///
 /// @file    virtual2.cc
 /// @author  jcx(yxjcxstack@gmail.com)
 /// @date    2018-05-03 15:09:45
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
	public:
		explicit
		Base(int ibase)
		: _ibase(ibase)
		{
			cout << "Base(int)" << endl;
		}

		virtual
		void display()
		{
			cout << "Base::display() ibase = " << _ibase << endl;
		}
	private:
		int _ibase;
};


class Derived
: public Base
{
	public:
		Derived(int ibase, int iderived)
		: Base(ibase)
		, _iderived(iderived)
		{
			cout << "Derived()" << endl;
		}

		void display()
		{
			cout << "Derived::display() _iderived = " << _iderived << endl;
		}

		void print()
		{
			cout << "Derived::print()" << endl;
		}

	private:
		int _iderived;
};

int main(void)
{
	Derived d1(10,20);//通过对象名进行访问，并不表现出多态性。
	d1.display();//静态联编，直接到代码区找相应的函数
		//	，这种情况下是有隐藏的
	//d1.Base::display();
	d1.print();

	Base & ref = d1;//通过一个基类引用调用d1
	ref.display();//底层实现还是指针，动态联编
	
	return 0;

}
