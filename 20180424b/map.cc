 ///
 /// @file    map.cc
 /// @author  jcx(yxjcxstack@gmail.com)
 /// @date    2018-04-24 08:08:01
 ///
 
#include <iostream>
#include <map>
#include <string>
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::pair;

template <typename Container>
void printContaiter(const Container & container)
{
	for(auto & elem:container)
	{
		cout << elem.first << " --> " << elem.second << endl;
	}
}

void test0()
{
	map<string, int> mapStrInt{
		pair<string, int> ("hello",1),
		std::make_pair("world",2),
		std::make_pair("hi",0),
		std::make_pair("hi",0) 

	};

	cout << mapStrInt["hi"] << endl;
	cout << mapStrInt["haha"] << endl;
	printContaiter(mapStrInt);
}

int main(void)
{
	test0();
	return 0;
}
