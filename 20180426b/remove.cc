 ///
 /// @file    remove.cc
 /// @author  jcx(yxjcxstack@gmail.com)
 /// @date    2018-04-27 07:58:56
 ///
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using std::cout;
using std::endl;
using std::remove;
using std::vector;
using std::ostream_iterator;
int test0(void)
{
	vector<int> numbers{1, 2, 3, 4, 5,
	6, 7, 8, 9, 10};	
	numbers[3] = numbers[6] =numbers[8] = 66;

	//erase-remove 惯用法
	numbers.erase(remove(numbers.begin(), numbers.end(),66),
				numbers.end());
	copy(numbers.begin(),numbers.end(),ostream_iterator<int>(cout, " "));
	cout << endl;
#if 0	
	在容器遍历的过程中不要做删除或者添加元素的操作
	for(auto it = numbers.begin(); it != numbers.end(); ++it)
	{
		if(*it == 66)
			numbers.erase(it);
	}
	return 0;
#endif
	return 0;
}

void test1(void)
{
	vector<int> numbers{1,2};
	bool flag = true;
	for(auto it = numbers.begin(); it != numbers.end(); ++it)
	{
		cout << "numbers' size = " << numbers.size() << endl;
		cout << "numbers' capacity = " << numbers.capacity() << endl;
		cout << "*it = " << *it << endl;
		if(flag)
		{
			numbers.push_back(3);
			flag = false;
		}
	}
}
int main(void)
{
	test1();
	return 0;
}
