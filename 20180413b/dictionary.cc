///
/// @file    dictionary.cc
/// @author  jcx(yxjcxstack@gmail.com)
/// @date    2018-04-13 08:14:46
///

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::istringstream;
using std::ostringstream;
using std::stringstream;
using std::vector;

class Dictionary
{
	public:
		Dictionary()
		: _word{0}
		, _number{0}
		{
			cout << "Dictionary()" << endl;
		}

		void read(const std::string & filename)
		{
			ifstream ifs(filename)
			if(!ifs)
			{
				cout << "ifstream open error!" << endl;
				return;
			}
			string sword;
			vector<string> word;
			vector<int> count;
			int i;
			while(getline(ifs, sword,' '))
			{
				istringstream iss(sword);
				iss >> word[i];
				if()
				{

				}


			}
		}
		void store(const std::string & ofilename)
		{

		}

	private:
		vector<string> _word;
		vector<int>	_number;
};

int main(void)
{
	Dictionary dic;
	string ifilename("~/cppgit/20180413b/The_Holy_Bible.txt");
	dic.read(ifilename);
	string ofilename("dic.txt");
	dic.store(ofilename);

	return 0;
}
