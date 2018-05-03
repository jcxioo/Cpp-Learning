 ///
 /// @file    auto_ptr.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-04-30 16:00:04
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{	cout << "Point(int,int)" << endl;	}

	void display() const{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

	~Point(){	cout << "~Point()" << endl;}
	
	friend std::ostream & operator<<(std::ostream & os, const Point & rhs);
private:
	int _ix;
	int _iy;
};

std::ostream & operator<<(std::ostream & os, const Point & rhs)
{
	os << "(" << rhs._ix
	   << "," << rhs._iy
	   << ")";
	return os;
}

shared_ptr<Point> getPoint()
{
	shared_ptr<Point> sp(new Point(5,6));
	return sp;
}

int main(void)
{
	shared_ptr<Point> sp(new Point(1,2));
	cout << "sp'get = " << sp.get() << endl;
	cout << "*sp = " << *sp << endl;

	shared_ptr<Point> sp2(sp);//复制语义shared_ptr可以
	cout << "*sp = " << *sp << endl;
	cout << "*sp2 = " << *sp2 << endl;
	
	cout << "sp' use_count = " << sp.use_count() << endl;

	shared_ptr<Point> sp3;
	sp3 = sp2 ;//赋值                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
	cout << "sp' use_count = " << sp.use_count() << endl;
	
	return 0;
}
