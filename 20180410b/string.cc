 ///
 /// @file    string.cc
 /// @author  jcx(yxjcxstack@gmail.com)
 /// @date    2018-04-10 11:09:07
 ///
 
#include <iostream>
#include <string.h>
#include <stdlib.h>
using std::cout;
using std::endl;
void test0()
{
	char str[] = "hello";//字符数组
	const char * pstr = "world";//C风格的字符串

	cout << "str = " << str << endl;
	cout << "pstr = " << str << endl;
	cout << "sizeof(str) = " << sizeof(str) << endl;
	

	char * p1 = (char* )malloc(sizeof(str)+strlen(pstr));
	strcpy(p1,str);
	strcat(p1,pstr);

	cout << "str = " << str << endl;
	cout << "pstr = "<< pstr << endl;
	cout << "p1 = "<< p1 << endl;
	
	for(int idx = 0; idx != sizeof(str); ++idx)
	{
		cout << str[idx] << "\n";
	}
	cout << endl; 
	free(p1);
}


void test1()
{
	using std::string;
	string s1 = "hello";
	string s2 = "world";
	string s3 = s1 + s2;
	cout << "s3 = " << s3 << endl;
	string s4;
	s4.append(s1).append(s2);//通过成员函数append完成拼接

	cout << "s3 = " << s3 << endl;
	cout << "s4 = " << s3 << endl;
	
	//求取字符串长度
	
	cout << "s4.size() = " << s4.size() << endl;
	cout << "s3.length = " << s3.length() << endl;
	
	//遍历字符串的方式
	for(size_t idx = 0; idx != s4.size();++idx)
	{
		cout << s4[idx] << " ";
	}
	cout << endl;
		
	//截取字符串中的子串
	string s5 = s4.substr(5,3);//第5个开始截取3个
	cout << "s5 = "<< s5 << endl; 

	string s6 = s5;
	cout << "s6 = "<< s6 << endl; 
	
	//字符串比较
	cout << (s1 == s2) << endl;
	cout << (s1 != s2) << endl;
	cout << (s5 == s6) << endl;


}


int main()
{
//	test0();
 	test1();
	return 0;
}

