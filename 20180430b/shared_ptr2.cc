 ///
 /// @file    shared_ptr2.cc
 /// @author  jcx(yxjcxstack@gmail.com)
 /// @date    2018-05-02 21:18:08
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;


class Child;
class Parent
{
	public:
		Parent() { cout << "Parent()" << endl;}
		~Parent() {cout << "~Parent()" << endl;}

		shared_ptr<Child> _childPtr;
	//	Base * base = derived;
};

class Child
{
	public:
		Child()	
		{ cout <<  "Child()" << endl;}
		~Child()
		{cout << "~child()" << endl;}
		shared_ptr<Parent> _parentPtr;

};


int main(void)
{
	shared_ptr<Parent> pParent(new Parent());
	shared_ptr<Child> pChild(new Child());

	pParent->_childPtr = pChild;
	pChild ->_parentPtr = pParent;
	//循环引用 没有调用析构函数 造成内存泄漏
	return 0;
}
