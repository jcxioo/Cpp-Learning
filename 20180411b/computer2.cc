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
		cout << "~Computer" << endl;
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

Computer com2("jaja",4000);
static Computer com3 ("test",1111);

int main(void)
{
	//位于栈上，栈对象
	Computer com("Mac",20000);
	com.print();

	int *p = new int (1);
	
	Computer *pc = new Computer("xiaomi",6000);
	pc -> print();
	
	delete pc;
	delete p;
	return 0;
}
