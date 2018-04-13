 ///
 /// @file    queue.cc
 /// @author  jcx(yxjcxstack@gmail.com)
 /// @date    2018-04-12 09:09:13
 ///
 
#include <iostream>

#define MaxSize 10
using std::cout;
using std::endl;

class Queue
{
	public:
		Queue()
		: _q{0}
		, _front(0)
		, _rear(0)
		{
			cout << "Queue()" << endl;
		}

		void push(int q)
		{
			if(!full())	
			{
				_q[_rear] = q;
				cout << "_q[" << _rear 
					<< "] = " << _q[_rear] 
					<<endl;
				_rear++;
			}
		}

		void pop()
		{
			if(!empty())
			{
				
				_q[_front] = 0;
				_front++;
				cout << "pop()" << endl;
				//cout << "_q[" << _front-1 
				//	<< "] = " << _q[_front-1] 
				//	<<endl;
		
			}
		}

		void front()
		{
			cout << "front =" << _q[_front] << endl;
		}

		void back()
		{
			cout << "back = " << _q[_rear-1] << endl;
		}

		bool full()
		{
			if((_rear+1)%MaxSize == _front)
			{
				cout << "Queue is full." << endl;
				return true;
			}else{
				return false;
			}
		}
		bool empty()
		{
			if(_front == _rear)
			{
				cout << "Queue is empty." << endl;
				return true;
			}else{
				return false;
			}
		}


	private:
		int _q[10];
		int _front;
		int _rear;

};

int main(void)
{
	Queue q;
	q.push(11);
	q.push(12);
	q.push(13);

	q.front();
	q.back();
	q.pop();
	q.front();
	q.back();
	
	q.push(14);
	q.front();
	q.back();
}
