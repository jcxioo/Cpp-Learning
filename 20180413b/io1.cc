 ///
 /// @file    io1.cc
 /// @author  jcx(yxjcxstack@gmail.com)
 /// @date    2018-04-13 02:26:05
 ///
 
#include <iostream>
#include <string>
#include <limits>
using std::cout;
using std::cin;
using std::endl;
using std::string;

int test0()
{
#if 0
	cout << "sizeof(cin)" << sizeof(cin) << endl;
	cout << "sizeof(cout)" << sizeof(cout) << endl;
#endif
	int a ;
	while(cin >> a)
	{
		cout << "a = " << a << endl;
	}
	cin.clear();
		cout << "a = " << a << endl;
	
}

int main()
{
	test0();

	return 0;




}
