 ///
 /// @file    String.cc
 /// @author  jcx(yxjcxstack@gmail.com)
 /// @date    2018-04-11 08:55:18
 ///
 
#include <iostream>
#include <string>
#include <string.h>
using std::cout;
using std::cin;
using std::endl;
using std::string;

class String
{
	public:
		String ()
		: _pstr (new char[1]())//加小括号后会自动初始化为0，不必再赋0
		{
			//*_pstr ='0';
			cout << "String " << endl;
		}

		String (const char *pstr)	
		: _pstr (new char[strlen(pstr)+1]())
		{
			strcpy(_pstr, pstr);
			cout << "String(const char *pstr)" << endl;
			//	<< pstr <<endl;
		}

		String(const String & rhs)//复制构造函数
		: _pstr(new char[strlen(rhs._pstr)+1]())
		{
			strcpy(_pstr, rhs._pstr);
			cout << "String(const String & rhs))" <<endl;
		}
	
		String & operator = (const String & rhs)
		{
			cout << "String & operator =(const String &)" << endl;
			if(this != &rhs)
			{
				delete [] _pstr;
				_pstr = new char[strlen(rhs._pstr) + 1]();
				strcpy(_pstr, rhs._pstr);
			}
			return *this;	
		}
			
		String & operator = (const char * pstr)
		{
			cout << "String & operator =(const char*)"	<< endl;
			delete [] _pstr;
			_pstr = new char[strlen(pstr)+1]();
			strcpy(_pstr,pstr);
			return *this;
		}

		String & operator += (const String & rhs)
		{
			cout << "String & operator +=(const String &) " << endl;
			strcat(_pstr,rhs._pstr);
			return *this;
		}

		String & operator += (const char * pstr)
		{
			cout << "String & operator +=(const char *) " << endl;
			strcat(_pstr,pstr);
			return *this;
		}

		char & operator[](std::size_t index)
		{
			static char Strnull='\0';
			if(index < strlen(_pstr))
			{
				return _pstr[index];
			}
			else{
			cout << "下标越界" << endl;
			return Strnull;	
			}
		}
		const char & operator[](size_t index) const
		{
			static char Strnull='\0';
			if(index < strlen(_pstr))
			{
				return _pstr[index];
			}
			else{
			cout << "下标越界" << endl;
			return Strnull;	
			}	
		}
		
		std::size_t size() const
		{
			cout << "size()" << endl;
			return strlen(_pstr);
		}

		const char *c_str() const
		{
			cout << "c_str()" << endl;
			
			return _pstr;
		}
		
		friend bool operator == (const String &,const String &);
		friend bool operator != (const String &,const String &);
		friend bool operator < (const String &,const String &);
		friend bool operator > (const String &,const String &);
		friend bool operator <= (const String &,const String &);
		friend bool operator >= (const String &,const String &);

	
		friend std::ostream & operator << (std::ostream & os , const String &s);
		friend std::istream & operator >> (std::istream & is ,  String & s); 
		~String()
		{
			delete [] _pstr;
			cout << "~String" << endl;
			
		}
		void print()
		{
			cout << _pstr << endl; 
		}
	private:
		char * _pstr;
};


bool operator == (const String & lhs,const String & rhs)
{
	return (lhs._pstr == rhs._pstr);
} 
bool operator != (const String & lhs,const String & rhs)
{
	return (lhs._pstr != rhs._pstr);	
}
 bool operator < (const String & lhs,const String & rhs) 
{
	return (lhs._pstr <  rhs._pstr);	
}
 bool operator > (const String & lhs,const String & rhs)
{
	return (lhs._pstr > rhs._pstr);	
}
 bool operator <= (const String & lhs,const String & rhs)
{
	return (lhs._pstr <= rhs._pstr);	
}
 bool operator >= (const String & lhs,const String & rhs)
{
	return (lhs._pstr >= rhs._pstr);	
}		

std::ostream & operator << (std::ostream & os , const String &s)
{
	os<<s._pstr<<endl;
	return os;
}

std::istream & operator >> (std::istream & is ,  String & s) 
{
	is >> s._pstr;
	return is;
}

String operator+(const String &	 lhs, const String & rhs)
{
	String s;
	s += lhs;
	s += rhs;
	return s;
}

String operator+(const String & lhs, const char * pstr) 
{
	String s;
	s += lhs;
	s += pstr;
	return s;
}

String operator+(const char * pstr, const String & rhs)
{
	String s;
	s += pstr;
	s += rhs;
	return s;
	
}

int main(void)
{
	String str1 = "Hello world";
	String str2("wangdao");

	cout << "str1 = ";
	str1.print();
	cout << "str2 = ";
	str2.print();

	String str3 = str2;
	cout << "str3 = ";
	str3.print();
		
	String str4;
	str4 = str2;
	cout << "str4 = ";
	str4.print();

	const char * pstr("hello");
	str4 = pstr;
	cout << "str4 = ";
	str4.print();
		
	String str5 = "world";
	str5 += str4;
	cout << "str5 = ";
	str5.print();

	String str6 = "HAHHAHAHAIHA";
	const char * s="hello world";
	size_t i;
	for (i = 0; i < (strlen(s)+1); ++i)
	{
			str6[i] = s[i]; 
	}
	cout << "str6 = ";
	for(i = 0; i < (strlen(s)+1);++i)
	{
		cout << str6[i];
	}

	cout <<"size str6 = " << str6.size() << endl; 
	char c[20];
	strcpy(c,str6.c_str());
	cout << "c = str6 = " << c << endl;

	cout << "str5 == str6 ?  " << (str5 == str6) << endl;
	cout << "str5 != str6 ?  " << (str5 != str6) << endl;
	cout << "str5 < str6 ?  " << (str5 < str6) << endl;
	cout << "str5 > str6 ?  " << (str5 > str6) << endl;
	cout << "str5 <= str6 ?  " << (str5 <= str6) << endl;
	cout << "str5 >= str6 ?  " << (str5 >= str6) << endl;
	
	String str7("HAHAHA");
	cin >> str7;
	cout << str7;
	
	cout << "str5 + str7 = " << (str5+str7) << endl; 
	cout << "str5 + c = " << (str5+c) << endl; 

	return 0;
}
