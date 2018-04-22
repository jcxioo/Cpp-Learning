 ///
 /// @file    COWstring.cc
 /// @author  jcx(yxjcxstack@gmail.com)
 /// @date    2018-04-19 09:25:43
 ///
#include <string.h>
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

class String
{
	class CharProxy
	{
		public:
			CharProxy(size_t idx, String & self)
			: _idx(idx)
			, _self(self)
			{}

			operator char (){
				return _self._pstr[_idx];
			}

			char & operator = (const char & ch);
		private:
			size_t _idx;
			String & _self;
	};
	public:
		String();
		String(const char *);
		String(const String & rhs);
		String & operator = (const String & rhs);
		~String();

		const char & operator[](size_t idx) const
		{
			return _pstr[idx];
		}
	//	char & operator[](size_t idx);
		CharProxy operator [] (size_t idx);
	
		size_t size()
		{
			return strlen(_pstr);
		}
		const char * c_str() const
		{
			return _pstr;
		}
		 
		size_t refcount() const
		{
			return ((int *)(_pstr - 4))[0];
		}

		friend std::ostream & operator << (std::ostream & os,const String & rhs);
	private:
		char * _pstr;
		
		void initRefcount()
		{
			((int*)(_pstr-4))[0]=1;
		}

		void increaseRefcount()
		{
			++(((int*)(_pstr-4))[0]);
		}

		void decreaseRefcount()
		{
			--(((int*)(_pstr-4))[0]);
		}
		
		void release()
		{
			decreaseRefcount();
			if(0 == refcount())
			{
				delete [](_pstr-4);
			}
		}
};

String::String()
: _pstr(new char[5]())
{	
	_pstr +=4;
	initRefcount();
	cout << "String()" << endl;
}

String::String(const char * pstr)
:_pstr(new char[strlen(pstr)+5]())
{
	cout << "String(const char *)" << endl;
	_pstr +=4;
	initRefcount();
	strcpy(_pstr,pstr);
}

String::String (const String & rhs)
:_pstr(rhs._pstr)
{
	increaseRefcount();
}

String & String::operator=(const String & rhs)
{
	if(this != & rhs)//避免自复制
	{
		release();//释放原有空间
		_pstr = rhs._pstr;
		increaseRefcount();
	}
	return *this;
}

String::~String()
{
	release();
	cout << "~String()" << endl;
}	

std::ostream & operator << (std::ostream & os,const String & rhs) 
{
		os << rhs._pstr;
		return os;
}

String::CharProxy String::operator [](size_t idx)
{
	return CharProxy(idx,*this);
}
char & String::CharProxy::operator=(const char & ch)
{
	if(_self.refcount()>1)
	{
		_self.decreaseRefcount();
		char * ptmp = new char[_self.size()+5]();
		strcpy(ptmp+4,_self._pstr);
		_self._pstr = ptmp +4;
		_self.initRefcount();
	}
	_self._pstr[_idx] = ch;
	return _self._pstr[_idx];
}

int main(void)
{
	String s1;
	String s2(s1);
	cout << "s1'refcount = " << s1.refcount() <<endl;
	cout << "s2'refcount = " << s2.refcount() <<endl;
	printf("s1'addr = %p\n",s1.c_str());
	printf("s2.addr = %p\n",s2.c_str());

	String s3("hello world");
	String s4(s3);
	cout << "s3 = " << s3 << endl;
	cout << "s4 = " << s4 << endl;
	cout << "s1'refcount = " << s1.refcount() <<endl;
	cout << "s2'refcount = " << s2.refcount() <<endl;
	printf("s3'addr = %p\n",s3.c_str());
	printf("s4'addr = %p\n",s4.c_str());
		
	String s5("s5 hello");
	s5 = s3;
	cout << "s3'refcount = " << s3.refcount() <<endl;
	cout << "s5'refcount = " << s5.refcount() <<endl;
	cout << "s3 = " << s3 << endl;
	cout << "s5 = " << s5 << endl;
	printf("s3'addr = %p\n",s3.c_str());
	printf("s5'addr = %p\n",s5.c_str());

	s5[0]='X';
	cout << "s3'refcount = " << s3.refcount() <<endl;
	cout << "s5'refcount = " << s5.refcount() <<endl;
	cout << "s3 = " << s3 << endl;
	cout << "s5 = " << s5 << endl;
	printf("s3'addr = %p\n",s3.c_str());
	printf("s5'addr = %p\n",s5.c_str());

	cout << "读操作 s5[0] = " << s5[0] << endl; 
	cout << "s5 = " << s5 << endl;
	printf("s5'addr = %p\n",s5.c_str());
	
	return 0;
}





