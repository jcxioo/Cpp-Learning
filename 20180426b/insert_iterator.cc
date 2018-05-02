 ///
 /// @file    insert_iterator.cc
 /// @author  jcx(yxjcxstack@gmail.com)
 /// @date    2018-04-26 21:33:46
 ///
 
#include <iostream>
#include <vector>
#include <iterator>
#include <list>
#include <set>
using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::set;
using std::back_insert_iterator;
using std::ostream_iterator;
using std::front_insert_iterator;
using std::insert_iterator;
//插入迭代器 back_insert_iterator
int main(void)
{
	vector<int> numbers1{1, 2, 3};
	list<int> numbers2{4, 5, 6};
	copy(numbers2.begin(), numbers2.end(),
			back_insert_iterator<vector<int>>(numbers1));
	//调用push_back 适用vector、list、deque
	cout << "vector: " ;
	copy(numbers1.begin(), numbers1.end(), ostream_iterator<int>(cout, ","));
	//把输出流当成容器来看待
	cout << endl;

	copy(numbers1.begin(),numbers1.end(),
			front_insert_iterator<list<int>>(numbers2));
	//前向迭代器 调用push_front 依次把1,2,3,4,5,6 copy进list
	//适用 list、deque
	cout << "list:";
	copy(numbers2.begin(),numbers2.end(),
			ostream_iterator<int>(cout," "));
	cout << endl;
	
	auto it = numbers2.begin();
	++it;++it;++it;
	copy(numbers1.begin(),numbers1.end(),
			insert_iterator<list<int>>(numbers2, it));
	cout << "list:";
	copy(numbers2.begin(),numbers2.end(),ostream_iterator<int>(cout , " "));
	cout << endl;

	set<int> numbers3;
	auto sit = numbers3.begin();
	copy(numbers1.begin(),numbers1.end(),
			insert_iterator<set<int>>(numbers3,sit));
	cout << "set<int>:";
	copy(numbers3.begin(),numbers3.end(),ostream_iterator<int>(cout, " "));
	cout << endl;

}
