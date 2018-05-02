 ///
 /// @file    Point3d.cc
 /// @author  jcx(yxjcxstack@gmail.com)
 /// @date    2018-05-01 10:54:39
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
	public:
		Point(int ix = 0, int iy = 0)
		: _ix(ix)
		, _iy(iy)
		{
			cout << "Point()" << endl;
		}
	int getY() const {return _iy;}

	void print() const {
		cout << "(" << _ix //对于基类的protected成员而言，是可以在派生类内部直接访问
			<< "," << _iy //_iy //对于基类的私有成员而言，不能在派生类内部直接访问
			<< ")" << endl;
	}
	protected:
		int _ix;
	
		int getX() const { return _ix;}
	private:
		int _iy;
};


class Point3d
:public Point
{
	public:
		Point3d(int ix, int iy, int iz)
		:Point(ix, iy)
		, _iz(iz)
		{cout << "Point3d(int, int ,int)"<< endl;}
		
		void display() const
		{
			cout << "(" << _ix
				<< "," << getY()
				<< ")" << _iz
				<< endl;
		}
	private:
		int _iz;
};

int main(void)
{
	Point3d pt3d1(1,2,3);
	pt3d1.print();
//	pt3d1.getX();//对于派生类对象而言，只有以公有继承方式访问基类的公有成员
	pt3d1.getY();
}

