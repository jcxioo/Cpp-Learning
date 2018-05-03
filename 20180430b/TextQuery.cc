///
/// @file    TextQuery.cc
/// @author  jcx(yxjcxstack@gmail.com)
/// @date    2018-04-25 08:47:54
///
#include <stdio.h>
#include <string.h> 
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <memory>
using std::cout;
using std::cin;
using std::endl;
using std::map;
using std::set;
using std::vector;
using std::pair;
using std::string;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::shared_ptr;
using std::fgets;
class TextQuery
{
	public:
		TextQuery()
		{
			cout <<	"TextQuery()"<< endl;	
		}
		void readFile(const string filename);
		void  query(const string & word);
	private:
		string line;
		vector<string> lines;
		map<string,set<int>> word2line;
		map<string,int> dict;
		int count_line = 0;
		bool isWord(const string & word)
		{
			for(size_t idx = 0; idx != word.size(); ++idx)
			{
				if (isdigit(word[idx]))
					return false;
			}
			return true;
		}
};
struct fileclose
{
	void operator()(FILE * fp)
	{
		fclose(fp);
	}
};

void TextQuery::readFile(const string filename)
{	
	shared_ptr<FILE> sfp(fopen(filename.c_str(),"r+"),fileclose());
	char buf[1000] = {0};
	while(fgets(buf,sizeof(buf),sfp.get()))
	{	
		line = buf;
		lines.push_back(line);  //把每行存入vector
		++count_line;			//记录行数	
		istringstream iss(line);
		string word;
		while(iss >> word)
		{
			if(isWord(word))
			{	
				word2line[word].insert(count_line);//word,行数 存入map-key,map-value
				dict[word]++;//单词和词频存入dict-key,value;
			}
		}
	}
}
void TextQuery::query(const string & word) 
{
	cout << "需要查询的单词为：" << word << endl
		<< "单词出现的次数为："  << dict[word] << endl;
	cout << "---------------------------------------" <<endl;
	auto it = word2line[word].begin();
	while(it != word2line[word].end())	
	{	cout << "(line " << *it+1 << ")"
		<< lines[*it-1] << endl;
		++it;
	}
}

int main(int argc,char * argv[])
{
	if(argc != 2 )
	{
		cout << "error args!" << endl;
		return -1;
	}
	string queryWord;
	cout << "请输入需要查询的单词：" << endl;
	cin >> queryWord;
	TextQuery tq;
	tq.readFile(argv[1]);
	tq.query(queryWord);
	return 0;
}
