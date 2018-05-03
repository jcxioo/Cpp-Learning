 ///
 /// @file    virtual.cc
 /// @author  jcx(yxjcxstack@gmail.com)
 /// @date    2018-05-02 10:45:34
 ///
 
#include <iostream>
using std::cout;	
using std::endl;

class Base
{
	public:
		Base(double dbase)
		: _dbase(dbase)
		{
			cout << "Base()" << endl;
		}

		virtual
		void display()
		{}

	private:
		double _dbase;
};
