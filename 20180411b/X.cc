 ///
 /// @file    X.cc
 /// @author  jcx(yxjcxstack@gmail.com)
 /// @date    2018-04-11 08:57:38
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class X
{
	public:
		//初始化成员时，成员初始化的顺序只与其
		//被声明时的顺序保持一致，而与其初始化列表中的顺序无关
		X(int iy)
		: _iy(iy)
		, _ix(_iy)//这里的顺序不是初始化的顺序
		{

		}
	void print()
	{
		cout << "(" << _ix
			<< "," << _iy
			<< ")" << endl;
	}
	private:
		int _ix;//此处声明的顺序才是初始化的顺序
		int _iy;
};


int main(void)
{
	X x(2);
	x.print();
}
