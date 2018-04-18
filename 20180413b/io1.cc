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
	int a ;
	while(cin >> a)
	{
		cout << "a = " << a << endl;
	}
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	
	cout << endl;
#endif
	string s1;
	while(std::getline(cin,s1))
	{
		cout << "s1 = " << s1 << endl;
	}

	return 0; 


}

int main()
{
	test0();

	return 0;




}
