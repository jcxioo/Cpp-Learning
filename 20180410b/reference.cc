 ///
 /// @file    reference.cc
 /// @author  jcx(yxjcxstack@gmail.com)
 /// @date    2018-04-10 09:49:36
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int test0()
{
	int number = 100;
	int ival = 1;
//	int & r;//引用不能单独存在  必须依附于实体
	int & ref = number;
//引用是一个变量的别名，一经初始化之后就不能再改变其指向。
	cout << "number = " << number << endl;
	
	ref = 20;
	cout << "number = " << ref << endl;
	
	ref = ival;//不会把ref重新绑定，而是将ival赋值给ref和number
	cout << "number = " << ref << endl;
	cout << "ref = " << ref << endl;
	cout << "ival = " << ref << endl;
		
	return 0;
}


void swap1(int *px, int * py)
{	
	int temp = *px;
	*px = *py;
	*py = temp;
}

void swap(int & x, int & y)
{
	int temp = x;
	x = y;
	y = temp;
}


int main(void)
{
	int a = 3, b = 4;
	cout << "a = " << a << endl
		 << "b = " << b << endl;
//	swap(&a,&b);
	swap(a,b);
	cout << "after swap ..." << endl;
	cout << "a = " << a << endl
		 << "b = " << b << endl;
	return 0;
}
