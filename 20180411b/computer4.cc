 ///
 /// @file    computer2.cc
 /// @author  jcx(yxjcxstack@gmail.com)
 /// @date    2018-04-11 08:08:26
 ///
 
#include <iostream>
#include <string>
#include <string.h>
using std::cout;
using std::endl;
using std::string;


class Computer
{
	public:
		Computer(const char * brand, float price)
		: _brand (new char[strlen(brand)+1]())
		, _price(price)	 
		{
		//	_brand = new char [strlen(brand)+1]();
			strcpy(_brand, brand);
			cout << "Computer (const char *, float)" << endl;
		}
	Computer(const Computer & rhs)
	: _brand (rhs._brand)
	, _price (rhs._price)
	{
		cout << "Computer(const Computer&)" << endl;
	}



	void setBrand (const char * brand);
	void setPrice(float price);



	void print()
	{
		cout << "品牌：" << _brand << endl
			<< "价格：" << _price << endl;
	}
	
	~Computer()
	{	// 清理工作
		delete [] _brand;
		cout << "~Computer()" << endl;
	}
	

	private:
		char * _brand;
		float _price;
};

int test0(void)
{
	Computer com("pad",9000);
	return 0;
}

int main(void)
{
	//位于栈上，栈对象
	Computer com1("Mac",20000);
	Computer com2 = com1;
	cout << "com1 = " ;
	com1.print();
	cout << "com2 = " ;
	com2.print();
	cout << endl;

	
	
	return 0;
}
