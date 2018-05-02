 ///
 /// @file    vector.cc
 /// @author  jcx(yxjcxstack@gmail.com)
 /// @date    2018-04-27 09:58:15
 ///
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::allocator;

template <typename T>
class Vector
{
	public:
		typedef T value_type;
		typedef T * iterator;
		typedef const T * const_iterator;

		Vector() 
		: _start(NULL)
		, _finish(NULL)
		, _end_of_storage(NULL)
		{};

		~Vector();

		void push_back(const T & value);
		void pop_back();
		size_t size() const {return _finish - _start;} 
		size_t capacity() const{return _end_of_storage - _start;} 

		const_iterator begin() const{ return _start;}
		const_iterator end()  const {return _finish;}
	private:
		void reallocate();
		static std::allocator<T>	_alloc;
	private: 
		T * _start;
		T * _finish;
		T * _end_of_storage;
};

template <typename T>
Vector<T>::~Vector()
{
	while(_start != _finish)
		_alloc.destroy(--_finish);
	if(_start)
		_alloc.deallocate(_start, capacity());
}
template <typename T>
std::allocator<T> Vector<T>::_alloc;

template <typename T>
void Vector<T>::push_back(const T & value)
{
	if(size() == capacity())
	{
		reallocate();//开辟空间
	}
	_alloc.construct(_finish++,value);//有空间就创建添加
}

template <typename T>
void Vector<T>::pop_back()
{	
	if(size())
		_alloc.destroy(--_finish);
	
}
	
template <typename T>
void Vector<T>::reallocate()
{
	size_t cap = capacity();
	size_t newCap = cap ? cap * 2 : 1;
	
	T * newStart = _alloc.allocate(newCap);
//	std::copy(_start, _finish, newStart); 会调用对象的赋值运算符，此时没有对象
	if(_start){
		std::uninitialized_copy( _start, _finish, newStart);	
		while( _start != _finish)
		_alloc.destroy(--_finish);
		_alloc.deallocate(_start, cap);
	}
	_start = newStart;
	_finish = newStart + cap;
	_end_of_storage = newStart + newCap;
}

class Point
{
	public:
		Point(int ix = 0, int iy = 0)
		: _ix(ix)
		, _iy(iy)
		{ cout << "Point()" << endl;}
	
		~Point()
		{ cout << "~Point()" << endl;}
	friend std::ostream & operator << (std::ostream & os, const Point & rhs);
	private:
		int _ix;
		int _iy;
};

std::ostream & operator << (std::ostream & os, const Point & rhs)
{
	os << "(" << rhs._ix 
		<< "," << rhs._iy
		<< ")" ;
	return os;
}
void printCapacity(const Vector<Point> & points)
{
	cout << "points's size = " << points.size() << endl;
	cout << "points's capacity" << points.capacity() << endl;
} 
void printVector (const Vector<Point> & points)
{
	for(auto & elem : points)
	{
		cout << elem << " "; 
	}
	cout << endl;
}


int main(void)
{
	Vector<Point> points;
	printCapacity(points);
	
	points.push_back(Point(1,2));
	printCapacity(points);
	
	points.push_back(Point(3,4));
	printCapacity(points);

	points.push_back(Point(5,6));
	printCapacity(points);

	return 0;
}
