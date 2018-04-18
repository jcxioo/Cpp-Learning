 ///
 /// @file    headclass.cc
 /// @author  jcx(yxjcxstack@gmail.com)
 /// @date    2018-04-13 08:31:17
 ///
 
#include <iostream>
#include <stdlib.h>
#include <string.h>
using std::cout;
using std::endl;

class Student
{
	public:
		Student(int number, const char * name)
		: _number(number)
		, _name(new char[strlen(name)+1]())
		{
			strcpy(_name,name);
		
			cout << "Student(int, const char *)" << endl;
		}

	void print() const 
	{
		cout << "number: " << _number << endl 
			<< "name: " << _name << endl;
	}
	
	void destroy()
	{
	//		this->~Student;//直接调析构函数不会执行operator delete
			delete this;
	}
	private:
		~Student()
		{
			cout << "~Student()" << endl;
			delete [] _name;
		}
	private:
		char * _name;
		int  _number;
};


int main(void)
{
	Student * pstu = new Student(1000,"haha");
	cout << "Stuent head "<< endl;
	pstu->print();
	pstu->destroy();
	//要求构造函数是public
	
//	Student stu(1000,"haha");//这里只能将析构函数私有
//	构造、析构均为public才能创建栈对象
//	stu.print();
	return 0;
}
