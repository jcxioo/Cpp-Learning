 ///
 /// @file    io2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-04-13 14:38:28
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
	//ifstream要求打开的文件必须存在
	ifstream ifs("io1.cc");
	if(!ifs.good())
	{
		cout << "ifstream open error!" << endl;
		return -1;
	}

	//char buff[1024] = {0};
	//ifs.getline(buff, 10);
	//ifs.read(buff, 10);
	//cout << buff << endl;
	
	vector<string> lines;
	
	string line;
	while(std::getline(ifs, line))
	{
		//cout << line << endl;
		lines.push_back(line);
	}
	return 0;
}

