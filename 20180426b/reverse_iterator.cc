 ///
 /// @file    reverse_iterator.cc
 /// @author  jcx(yxjcxstack@gmail.com)
 /// @date    2018-04-26 21:58:20
 ///
 
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::reverse_iterator;
using std::vector;
// reverse_itrerator 反向迭代器 
// rbegin指向最后一个元素，rend指向第一个元素前一个位置。
int main(void)
{
	vector<int> numbers{1, 2, 3, 4, 5};
	vector<int>::reverse_iterator rit = numbers.rbegin();
	while(rit != numbers.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
	return 0;
}

