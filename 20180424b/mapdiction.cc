///
/// @file    dictionary.cc
/// @author  jcx(yxjcxstack@gmail.com)
/// @date    2018-04-13 08:14:46
///

#include <string.h>

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::multimap;
using std::ifstream;
using std::ofstream;
using std::istringstream;
class Dictionary
{
	public:
		Dictionary()
		{
			cout << "Dictionary()" << endl;
		}

		void read(const string & filename)
		{
			ifstream ifs(filename);
			if(!ifs)
			{
				cout << "ifstream open error!" << endl;
				return;
			}
			string line;
			int count = 0;
			while(getline(ifs, line))
			{
				istringstream iss(line);
			 	string word;
				while(iss >> word)
				{
					//循环读取单词，会判断空格
					if(isWord(word))
						processWord(word);			
				}
				++count;
			if((count % 100) == 0)//每100行打印一次
				{
					cout << "count = " << count << endl;
				}
 		}
			ifs.close();
		}
		void store(const string & filename)
		{
				ofstream ofs(filename);
				if(!ofs){
					cout << "ofstream open error!" << endl;
					return;
				}
				for (auto & record : _mapdict)
				{
					ofs << record.first << " " << record.second << "\n";
				}
				ofs.close();
		}
	private:
		bool isWord(const string & word)
		{
			for(size_t idx = 0; idx != word.size(); ++idx)
			{
				if(isdigit(word[idx]))
					return false;
			}
			return true;
		}

		void processWord(const string & word)
		{
					_mapdict[word]++;		
		}			
		map<string,int> _mapdict;
};

int main(void)
{
	Dictionary dictionary;
	string filename("/home/jcxioo/cppgit/20180416hw2/The_Holy_Bible.txt");
	dictionary.read(filename);
	dictionary.store("mapdic.txt");

	return 0;
}
