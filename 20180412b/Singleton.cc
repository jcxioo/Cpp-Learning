 ///
 /// @file    Singleton.cc
 /// @author  jcx(yxjcxstack@gmail.com)
 /// @date    2018-04-12 21:20:41
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//单例模式：要求一个类只能创建一个对象
//1、该对象不能是栈对象/全局对象
//2、该对象只能是堆对象
class Singleton
{
	public:

	private:
		Singleton(){cout << "Singleton()" << endl;}
}

int main(void)
{
	//Singleton s1;
	//Singleton s2;
	

}
