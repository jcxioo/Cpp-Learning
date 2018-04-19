 ///
 /// @file    AR_Singleton.cc
 /// @author  jcx(yxjcxstack@gmail.com)
 /// @date    2018-04-18 04:42:38
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Singleton
{
	class AutoRelease	
	{
		public:
			AutoRelease() {cout << "AutoRelease() " << endl; }
			~AutoRelease()
			{
				if(_pInstance)
				{
					delete _pInstance;
					cout << "~AutoRelease()" << endl;
				}
			}
	};

	public://多线程下 非线程安全
		static Singleton * getInstance()
		{
			if(NULL == _pInstance)
			_pInstance = new Singleton;
			return _pInstance;
		}
		static void destroy()
		{
			if(_pInstance)
			{
				delete _pInstance;
			}
		}
	private:
		Singleton() {cout << "Singleton()" << endl;}
		~Singleton(){cout << "~Singleton()" << endl;}
		static Singleton * _pInstance;
		static AutoRelease _auto;
};

//Singleton * Singleton::_pInstance;//饿汉模式 非线程安全
Singleton * Singleton::_pInstance = getInstance();//饱汉模式 线程安全
Singleton::AutoRelease Singleton::_auto;

int main(void)
{
	Singleton * p1 = Singleton::getInstance();
	Singleton * p2 = Singleton::getInstance();
	cout << "p1 = " << p1 << endl;
	cout << "p2 = " << p2 << endl;

//	Singleton::destroy();
	return 0;
}
