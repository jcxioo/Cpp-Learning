 ///
 /// @file    new.cc
 /// @author  jcx(yxjcxstack@gmail.com)
 /// @date    2018-04-10 09:27:24
 ///
#include <stdlib.h>
#include <iostream>
#include <string.h>
using std::cout;
using std::endl;


//malloc/free  与 new/delete的差别
//
//1.malloc/free 是库函数，new/delete 是表达式。
//2.malloc只负责开辟空间，并不会初始化空间的内容
//	new表达式除了开辟空间，他还会进行初始化。

void test0()
{
	int *p1 = (int *)malloc(sizeof(int));
	*p1 = 10;

	cout << "*p1 = " << *p1 << endl;

	int *p2 = (int *)malloc(10 * sizeof(int));
	memset(p2,0,10*sizeof(int)); 
	for(int idx = 0;idx != 10; ++idx)
	{
		p2[idx] = idx ;
	}
	for(int idx = 0; idx != 10; ++idx)
	{
		cout << p2[idx] << endl;
	}

	free(p2);
	free(p1);
}

void test1()
{
	int *p1 = new int(10);
	cout << "*p1 = " << *p1 << endl;

	int *p2 = new int[10]();

	for(int idx = 0;idx != 10; ++idx)
	{
		p2[idx] = idx ;
	}
	for(int idx = 0; idx != 10; ++idx)
	{
		cout << p2[idx] << endl;
	}
	
	delete p1;
	delete [] p2;//回收数组需要加[]
}



int main()
{
	test0();
	test1();
}

