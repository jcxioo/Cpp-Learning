 ///
 /// @file    stackclass.cc
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
		~Student()
		{
			cout << "~Student()" << endl;
			delete [] _name;
		}



	void print() const 
	{
		cout << "number: " << _number << endl 
			<< "name: " << _name << endl;
	}

	private:
		void * operator new (size_t sz);
		void operator delete (void * ret);

	private:
		char * _name;
		int  _number;
};


int main(void)
{
//		Student * pstu = new Student(1000,"haha");
	//要使该句出错,不能把构造函数私有，因为会导致栈对象也无法创建
	//考虑new的实现，可以把operator 和 delete私有，达到不能生成堆对象的目的。
	
	Student stu(1000,"haha");
	stu.print();
	return 0;
}
