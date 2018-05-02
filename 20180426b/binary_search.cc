 ///
 /// @file    binary_search.cc
 /// @author  jcx(yxjcxstack@gmail.com)
 /// @date    2018-04-27 09:35:34
 ///
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using std::cout;
using std::endl;
using std::vector;
using std::ostream_iterator;
using std::lower_bound;

int main(void)
{
	vector<int> numbers{2, 3, 4, 5, 1, 3, 4,5, 6,7,7,4,};
	std::sort(numbers.begin(),numbers.end());
	std::copy(numbers.begin(),numbers.end(),std::ostream_iterator<int>(cout, " "));
	cout << endl;
	cout << std::boolalpha << std::binary_search(numbers.begin(),numbers.end(), 10);
	cout << endl;
	cout << std::binary_search(numbers.begin(),numbers.end(),2);
	cout << endl;

	auto it1 = std::lower_bound(numbers.begin(),numbers.end(),3);
	auto it2 = std::upper_bound(numbers.begin(),numbers.end(),3);
	while(it1 != it2)
	{
		cout << *it1 << ",";
		++it1;
	}
	cout << endl;
}
