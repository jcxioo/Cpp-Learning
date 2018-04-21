 ///
 /// @file    templateQueue.cc
 /// @author  jcx(yxjcxstack@gmail.com)
 /// @date    2018-04-20 08:29:08
 ///
#include "Mylogger.h" 
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

template <typename Type, size_t ksize = 10>
class Queue
{
public:
		Queue()
		: _front(0)
		, _rear(0)
		, _arr(new Type[ksize]())
		{
			LogDebug("Queue()");
		}
		
		~Queue();
			
		bool full() const;
		bool empty() const;
		void push(const Type & type);
		void pop();
		Type front();
		Type back();

private:
		int _front;
		int _rear;
		Type * _arr;

};

template <typename Type, size_t ksize>
Queue<Type, ksize>::~Queue()
{
	LogDebug("~Queue()");
	delete [] _arr;
}

template <typename Type, size_t ksize>
bool Queue<Type, ksize>::empty() const
{
	return   _front == _rear;
}

template <typename Type, size_t ksize>
bool Queue<Type, ksize>::full() const
{

	return _front == (_rear + 1)% ksize;
}

template <typename Type, size_t ksize>
void Queue<Type, ksize>::push(const Type & t) 
{
	if(full())
	{
		LogInfo("Queue is full.");
	}else{
		_arr[++_rear] = t;
	}
}

template <typename Type, size_t ksize>
void Queue<Type, ksize>::pop() 
{
		if(empty())
		{
			LogInfo("Queue is empty,");
		}else{
			--_rear;
		}

}


template <typename Type, size_t ksize>
Type Queue<Type, ksize>::front() 
{
	return _arr[_front];
}

template <typename Type, size_t ksize>
Type Queue<Type, ksize>::back() 
{
	return _arr[_rear];
}


void test0(void)
{
	Queue<int> queue;
	LogInfo("Queue is empty? %d",queue.empty());
	queue.push(1);
	LogInfo("Queue is empty? %d",queue.empty());

	for (size_t idx = 2; idx != 12 ; ++idx )
	{
		queue.push(idx);
	}
	LogInfo("Queue is full? %d",queue.full());

	while(!queue.empty())
	{
		LogInfo("%d",queue.back());
		queue.pop();
	}
	LogInfo("Queue is empty? %d",queue.empty());
}

void test1(void)
{
	Queue<string> queue;
	LogInfo("Queue is empty? %d",queue.empty());
	queue.push("haha");
	LogInfo("Queue is empty? %d",queue.empty());

	for (size_t idx = 1; idx != 12 ; ++idx )
	{
		queue.push(string(2,'A'+ idx));
	}
	LogInfo("Queue is full? %d",queue.full());

	while(!queue.empty())
	{
		LogInfo("%s",queue.back().c_str());
		queue.pop();
	}
	LogInfo("Queue is empty? %d",queue.empty());
}

int main(void)
{
	test0();
	test1();
	return 0;
}

