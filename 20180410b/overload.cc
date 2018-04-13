///
/// @file    overload.cc
/// @author  jcx(yxjcxstack@gmail.com)
/// @date    2018-04-10 10:23:44
///
#include <stdio.h> 
#include <iostream>
using std::cout;
using std::endl;
//c++ 支持函数重载
//实现原理 名字改编 name mangling
//具体步骤 当函数名称相同时，会根据参数的类型、个数、顺序不同改编
//
//extern "C"
//{
//	int add(int x, int y)
//	{
//		return x + y;
//	}
//}
	int add(int x, int y = 0)
	{
		return x + y;
	}


int add(int x, double y,int z)
{
	return x + y + z;
}

int main()
{
	int a = 3,b = 4 ,c = 5;
	add(a,b,c);
	cout << "add(a) =  " << add(a) << endl;
	return 0;
}

