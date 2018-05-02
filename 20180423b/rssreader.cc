 ///
 /// @file    rssreader.cc
 /// @author  jcx(yxjcxstack@gmail.com)
 /// @date    2018-04-23 09:15:16
 ///
#include "tinyxml2.h" 
#include <iostream>
#include <string>
#include <regex>
#include <boost/regex.hpp>
#include <boost/algorithm/string.hpp>
using std::cout;
using std::endl;
using std::string;

void test(void)
{
	using namespace tinyxml2;

	XMLDocument doc;
//	cout << "000" << endl;
	doc.LoadFile("coolshell.xml");
//	cout << "111" << endl;
	XMLElement * proot = doc.FirstChildElement("rss");
	XMLElement * pchannel = proot -> FirstChildElement("channel");
	XMLElement * pitem = pchannel -> FirstChildElement("item");
	XMLElement * ptitle = pitem->FirstChildElement("title");
	XMLElement * plink = pitem->FirstChildElement("link");
	XMLElement * pdescription = pitem->FirstChildElement("description");
	XMLElement * pcontent =  pitem->FirstChildElement("content:encoded");	

	string title;
	string link;
	string description;
	string content;
	
	if(ptitle) title = string (ptitle ->GetText());
	if(plink) link = string (plink ->GetText());
	if(pdescription) description = string (pdescription ->GetText());
	if(pcontent) content = string (pcontent ->GetText());

	cout << "title: "  << title << endl
		<< "link: " << link << endl
		<< "description: " << description << endl;

		boost::regex re("<.*?>");
		cout << endl;
		cout << boost::regex_replace(content, re, string()) << endl;
		int cnt = 1;
	
		string page = 
			"<doc>\n"
			"	<docid>" + std::to_string(cnt) + "</docid>"
			"	<title>" + title + "</title>\n"
			"	<link>" + link + "</link>\n"
			"	<content>" + content + "</content>\n"
			"</doc\n>";

	XMLDocument::SaveFile( filename,)
}

int main(void)
{
	test();
	return 0 ;
}
