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

		void func1()
		{
			//有一个this指针,动态联编，表现多态性
			this->display();
		}

		void func2()
		{
			Base::display();
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
	Base base(1);
	base.func1();
	base.func2();
	cout << endl;

	Derived d1(10,11);
	d1.func1();//动态联编
	d1.func2();
	return 0;

}
