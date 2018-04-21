 ///
 /// @file    templateDefaultArg.cc
 /// @author  jcx(yxjcxstack@gmail.com)
 /// @date    2018-04-20 02:33:20
 ///
 
#include <iostream>
using std::cout;
using std::endl;

template <typename T, int number = 2>
T add (T t)
{
	return t + number;
}

int main(void)
{
	int a = 1 ;
	cout << add(a) << endl;
	return 0 ;
}
