 ///
 /// @file    sizeof.cc
 /// @author  jcx(yxjcxstack@gmail.com)
 /// @date    2018-05-03 16:47:09
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Example
{

	public:
		Example(int & ref)
		: _ref(ref)
		{}
		virtual void display(){}
	private:
		//虚函数指针vfptr 8
		int _ia;			//4
		double _ib;			//8
		char _iarr[3];		//3
		short _sd[5];		//10
		int & _ref;			//8
		static int _if;		//全局静态区 4
};

int main(void)
{
	cout << "sizeof Example()" << sizeof(Example)<<endl;	
}
