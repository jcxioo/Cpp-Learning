 ///
 /// @file    for_each.cc
 /// @author  jcx(yxjcxstack@gmail.com)
 /// @date    2018-04-26 23:23:42
 ///
 
#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::cout;
using std::endl;
using std::for_each;

void test(void)//test 本质是地址值 
{
	cout << "test()" << endl;
}

typedef void(*Function)(void);


int test0(void)
{
	Function f1 = test;
	f1();
	return 0;
}

void test1 (void)
{
	int a = 10;
	int b = 100;
	vector<int> numbers{1, 2, 3, 4, 5, 6};
	for_each(numbers.begin(),numbers.end(),[](int number){//lambda表达式代表的是匿名对象
			cout <<number << " ";
	});
	cout << endl;
	for_each(numbers.begin(), numbers.end(),[&](int number){
	cout << number << "a = " << a++ << ",b = " << b++ << endl;
	});
}

void test2(void)
{
	vector<int> numbers{1, 2, 3, 4, 5, 6};
	std::less<int> lt;//创建一个less的对象 lt(1,2);//返回值是bool类型，符合一元断言要求
//	std::replace_if(numbers.begin(),numbers.end(),std::bind1st(lt,3),7);//用函数适配器bind,lt的第一个值为3，进行less比较，如果为真则换为7
	std::replace_if(numbers.begin(),numbers.end(),std::bind2nd(lt,3),7);//用函数适配器bind
	//UnaryPredicate 一元断言 eg.bool类型 	
	for(auto & elem : numbers)
	{
		cout << elem << " ";
	}
	cout << endl;
}
int main(void)
{
//	test1();
	test2();
	return 0;
}
