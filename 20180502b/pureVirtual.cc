 ///
 /// @file    pureVirtual.cc
 /// @author  jcx(yxjcxstack@gmail.com)
 /// @date    2018-05-03 17:20:28
 ///
#include <math.h> 
#include <iostream>
using std::cout;
using std::endl;
//
//面前对象的方式：继承+多态
//优点： 扩展代码很方便
//面向对象进行编程
class Figure{
	public:
		virtual void display() = 0;
		virtual double area() = 0;
};

class Rectangle
: public Figure
{
	public:
		Rectangle(double length, double width)
		: _length(length)
		, _width(width)
		{}

		void display(){
				cout << "Rectangle: " ;		
		}

		double area()
		{
			return _length * _width;
		}

	private:
		double _length;
		double _width;
};

const double PI = 3.14159;

class Circle
:public Figure
{
	public:
		Circle(double radius)
		: _radius(radius)
		{}

		void display(){
			cout << "Circle: ";
		}

		double area(){
			return PI * _radius * _radius;
		}

	private:
		double _radius;
};

void printFigure(Figure * fig)
{
	fig->display();
	cout << fig->area() << endl;
}

int main(void)
{
	Rectangle rectangle(2,5);
	Circle circle(2);
	printFigure(&rectangle);
	printFigure(&circle);
	
	return 0;
}
