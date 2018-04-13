 ///
 /// @file    computer.cc
 /// @author  jcx(yxjcxstack@gmail.com)
 /// @date    2018-04-11 03:38:41
 ///
 
#include <iostream>
#include <string.h>
#include <string>
using std::cout;
using std::endl;
using std::string;

struct Person
{	
	//默认访问权限是public
	
	void setName(const string & name)
	{
		_name = name;
	}

	void setGender(bool gender)
	{
		_gender = gender;
	}

	void print()
	{
		cout << "姓名：" << _name << endl
			<< "性别：" << _gender << endl;
	}
	
	string _name;
	bool _gender;
};

class Computer
{
	//默认访问权限是private
	public://public 称为类对外提供的服务或接口

	void setBrand(const char * brand);
	void setPrice(float price);
	
	void print();

private://体现了类的封装性
	char _brand[20];
	float _price;
	
};

void Computer::setBrand(const char * brand)
{
	::strcpy(_brand,brand);
}

void Computer::setPrice(float price)
{
	_price = price;
}

int test0()
{
	Computer com;
	com.setBrand("ThinkPad");
	com.setPrice(8888);
	return 0;
}



int main()
{
	Person person;
	person._name = "Mike";
	person._gender = true;
	person.print();

	person.setName("Sue");
	person.setGender(false);
	person.print();
	
	test0();
	
	return 0;
}
