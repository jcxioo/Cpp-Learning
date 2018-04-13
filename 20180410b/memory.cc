 ///
 /// @file    memory.cc
 /// @author  jcx(yxjcxstack@gmail.com)
 /// @date    2018-04-11 00:50:41
 ///
 
#include <iostream>
#include  <stdio.h>

int a = 0;
char * p1;
int main()
{
	int b;
	char s[]= "123456";
	char * p2;
	const char *p3 = "123456";
	static int c = 0 ;
	p1 = new char [10];
	printf("&a = %p\n",&a);
	
	printf("p1 = %p\n",p1);
	printf("&p1 = %p\n",&p1);
	
	printf("&b = %p\n",&b);
	printf("&s = %p\n",&s);
	
	printf("p2 = %p\n",p2);
	printf("&p2 = %p\n",&p2);

	printf("p3= %p\n",p3);
	printf("&p3 = %p\n",&p3);

	printf("&c = %p\n",&c);
	printf("&main = %p\n",main);
}	
