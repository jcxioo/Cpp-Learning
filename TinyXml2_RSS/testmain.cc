///
/// @file    testmain.cc
/// @author  jcx(yxjcxstack@gmail.com)
/// @date    2018-04-22 09:18:43
///
#include"tinyxml2.h"  
using namespace std;  
using namespace tinyxml2;  
void example1()  
{  
	XMLDocument doc;  
	doc.LoadFile("test.xml");  
	const char* content= doc.FirstChildElement( "Hello" )->GetText();  
	printf( "Hello,%s", content );  
}  

int main()  
{  
	example1();  
	return 0;  
}
