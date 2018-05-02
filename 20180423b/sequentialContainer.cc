 ///
 /// @file    sequentialContainer.cc
 /// @author  jcx(yxjcxstack@gmail.com)
 /// @date    2018-04-23 08:18:13
 ///
 
#include <iostream>
#include <vector>
#include <list>
#include <deque>
using std::cout;
using std::endl;
using std::vector;
using std::deque;
using std::list;

int test(void)
{
	int arr[] = {1, 2, 3, 4, 5};
	vector<int> vecInt(5, 1);
	//vector<int> vecInt(arr, arr + 4);
	cout << "arr: " <<  arr << endl;		
	for (auto & number : vecInt)
	{ cout << number << " ";}
	cout << endl;
	cout << "vector[3]" << vecInt[3] << endl;//vector支持随机访问,时间复杂度为O(1)

	auto it = vecInt.begin();
	++it;

	cout << "vecInt'size = " << vecInt.size() << endl;
	cout << "capacity = " << vecInt.capacity() << endl;
	vecInt.insert(it, 3, 5);

	
	
	return 0 ;
}

int main(void)
{
	test();
	return 0;
}
