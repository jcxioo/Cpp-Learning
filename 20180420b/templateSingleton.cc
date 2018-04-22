///
/// @file    templateSingleton.cc
/// @author  jcx(yxjcxstack@gmail.com)
/// @date    2018-04-21 02:56:28
///

#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <iostream>
using std::cout;
using std::endl;
using std::string;

class Point
{
	public:
	Point()
	: _ix(0)
	, _iy(0)
	{
		cout << "Point()" << endl;
		cout << "ix = " << _ix << ", iy = " << _iy << endl;
	}

	Point(int ix, int iy)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int , int)" << endl;
		cout << "ix = " << _ix << ", iy = " << _iy << endl;
	}

	~Point()
	{
		cout << "~Point()" << endl;
	}

	private:
		int _ix;
		int _iy;
};
class Computer
{
	public:
	Computer(const char * brand, float price)
	: _brand(new char [strlen(brand)+1]()) 
	, _price(price)
	{
		strcpy(_brand, brand);
		cout << "Computer(const char *, float)" << endl;
		cout << _brand <<" , " << _price << endl;
	}

	~Computer()
	{
		delete [] _brand;
		cout << "~Computer()" << endl;
	}
	private:
		char * _brand;
		float _price;
};

template <typename Type>
class Singleton
{
	public:
		class AutoRelease
		{
			public:
				AutoRelease() {cout << "AutoRelease()" << endl;}
				~AutoRelease()
				{
					if(_pInstance)
					{
						delete _pInstance;
						cout << "~AutoRelease()" << endl;
					}
				}
		};
	public:
		template <typename T1, typename T2>
		static Type * getInstance(T1 t1 , T2 t2)
		{
			if(NULL == _pInstance)
			{	
				_auto;
				_pInstance = new Type(t1, t2);
			}
			return _pInstance;
		}

	private:
		Singleton() {cout << "Singleton()" << endl;}
		~Singleton() {cout << "~Singleton()"<< endl;}
		static 	Type * _pInstance;
		static  AutoRelease _auto;
};

template <typename Type>
Type * Singleton<Type>::_pInstance ;

template <typename Type>
typename Singleton<Type>::AutoRelease Singleton<Type>::_auto;



int main(void)
{
	Computer * p1 = Singleton<Computer>::getInstance("xiaomi",6666);
	Computer * p2 = Singleton<Computer>::getInstance("hahah",6666);
	Point * p3 = Singleton<Point>::getInstance(1,2);
	Point * p4 = Singleton<Point>::getInstance(1,2);

	return 0;
}

