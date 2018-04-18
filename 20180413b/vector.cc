 ///
 /// @file    vector.cc
 /// @author  jcx(yxjcxstack@gmail.com)
 /// @date    2018-04-13 05:49:50
 ///
 
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

void printVectorCapacity(vector<int> & vec)
{
	cout << "vec's size = " << vec.size() << endl
		<< "vec's capacity = " << vec.capacity() << endl;
}

int main(void) 
{

	vector<int> numbers;
	cout << "sizeof (numbers) = " << sizeof(numbers) << endl;

	numbers.reserve(1000);//只开空间，并不会创建对象

	printVectorCapacity(numbers);
	numbers.push_back(1);
	printVectorCapacity(numbers);
	numbers.push_back(2);
	printVectorCapacity(numbers);
	numbers.push_back(3);
	printVectorCapacity(numbers);
	numbers.push_back(4);
	printVectorCapacity(numbers);
	numbers.push_back(5);
	printVectorCapacity(numbers);
	numbers.push_back(6);
	printVectorCapacity(numbers);
	
	cout << "sizeof(numbers) = " << sizeof(numbers) << endl;
	cout << endl;

	for(size_t idx = 0; idx != numbers.size();++idx)
	{
		cout << numbers[idx] << " ";
	}
	cout << endl;


	for(auto & number: numbers) // C++11的遍历方式
	{
		cout << number << " ";
	}
	cout << endl;

	vector<int> :: iterator it;//迭代器相当于一个指针~
	for(it = numbers.begin();it != numbers.end();++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}
