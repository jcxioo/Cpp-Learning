 ///
 /// @file    Stack.cc
 /// @author  jcx(yxjcxstack@gmail.com)
 /// @date    2018-04-12 05:18:07
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Stack
{
	public:
		Stack()
		: _s{0}
		, _top(0)
		{
			cout << "Stack()" << endl;
		}	
		void push(int s )
		{
			if(!full())
			{
				_s[_top] = s;	
				cout << "push(int) _s[" 
					<<	_top  <<"] = "
					<< _s[_top]	<<endl;
				_top++;	
			}
		}	
		void top()
		{
			if(!empty())
			{
				_top--;
				cout << "Stack Top = " << _s[_top] <<endl;
				_top++;
			}
		}
		void pop()
		{
			if(	!empty())	
			{
				_s[_top-1] = 0; 
				cout << "pop()" << endl;
				_top--;
			}	
		}
		bool empty()
		{
			if(_top)
			{	
				return false;
			}else{
				cout << "Stack is empty." << endl;
				return true;
			}
		}
		bool full()
		{	
			if(_top<10)
			{
				return false;
			}else{
				cout << "Stack is full." << endl; 
				return true;
			}
		}
	private:
		int  _s[10];
		int _top;

};

int main(void)
{
	Stack S;
	S.push(10);
	S.push(12);
	S.push(14);
	S.top();
	S.pop();
	S.top();
}
