 ///
 /// @file    set.cc
 /// @author  jcx(yxjcxstack@gmail.com)
 /// @date    2018-04-24 03:51:30
 ///
 
#include <iostream>
#include <math.h>
#include <set>
using std::cout;
using std::endl;
using srd::set;

template <typename Container>
void printContainer(const Container & container )
{
	typename Container::const_iterator cit = container.begin();
	while(cit != container.end())
	{

		cout << *cit << " " ;
		++cit;
	}
	cout << endl;
}

int test0(void)
{
	int arr[10] = {2,3,2,3,2,3,4,2,1,5};

	set<int> setInt(arr, arr+10);
	cout << "set'size = " << setInt.size() << endl;
	printContainer(setInt);

	
	return 0 ;
}
