 ///
 /// @file    const.cc
 /// @author  jcx(yxjcxstack@gmail.com)
 /// @date    2018-04-10 03:51:41
 //
 //

#include <iostream>
using std::cout;
using std::endl;
//编辑 --> 预编译 --> 编译 --> 链接 --> 执行

#define MAX 100
//1、宏定义发送时机：预编译（预处理），
//   简单的执行字符串的替换,没有类型检查。
//2、const 常量发生时机：编译，有类型检查


int main()
{
	int a = 1;
	const int b = 10;
//	const int c;//uninitialized 未初始化
	
	cout << a *MAX << endl;
	cout << "const b = " << b << endl;
}
