 ///
 /// @file    io2.cc
 /// @author  jcx(yxjcxstack@gmail.com)
 /// @date    2018-04-13 05:19:12
 ///
 
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::vector;

int main(void)
{
	ifstream ifs("test.txt");

	if(!ifs.good())
	{
		cout << "ifstream open error!" << endl;
		return -1;
	}
	
#if 0
	char buff[1024] = {0};
	ifs.getline(buff, 10);
	ifs.read(buff, 10);
	cout << buff << endl;

#endif

	vector<string> lines;

	string line;
	while(std::getline(ifs,line))
	{

		lines.push_back(line);
		cout << line << endl;
	}
	
	
	return 0;
	
	ifs.close();
}
