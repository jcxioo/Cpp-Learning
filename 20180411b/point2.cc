 ///
 /// @file    point.cc
 /// @author  jcx(yxjcxstack@gmail.com)
 /// @date    2018-04-11 08:33:40
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
	public:
	//当没有人为构造函数,编译器会自动提供一个默认构造函数
	//构造函数可以进行重载
		
	Point()
	: _ix(0)
	, _iy(0)
	{
		cout << "Point()" << endl;
	}
	//一旦定义了自己的构造函数后，编译器不再提供
		Point(int ix, int iy = 0)	
		: _ix(ix)
		, _iy(iy)
		{
			cout << "Point(int, int)" << endl;
		}

	void print()
	{
		cout << "(" << _ix 
			<< "," << _iy
			<< ")" << endl;
	}
	~Point()
	{
		cout << "~Point" << endl;
	}

	private:
	int _ix;
	int _iy;

};

int test0(void)
{
	int a(1); 
	cout << "a = " << a << endl;

	Point pt1(1,2);
	pt1.print();

	Point pt2;
	pt2.print();

	Point pt3(1);
	pt2.print();
	return 0;
}

int main (void)
{
	test0();
	return 0;
}
