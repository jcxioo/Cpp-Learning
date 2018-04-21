 ///
 /// @file    templateStack.cc
 /// @author  jcx(yxjcxstack@gmail.com)
 /// @date    2018-04-20 04:59:56
 ///
#include "Mylogger.h" 
#include <iostream>
using std::cout;
using std::endl;

template <typename Type, size_t kSize = 10>  
class Stack
{
	public:
		Stack()
		: _top(-1)
		, _base(new Type[kSize]())
		{
				LogDebug("Stack()");
		}

		~Stack();

		bool empty() const;
		bool full() const;
		void push(const Type & type);
		void pop();
		Type top();

	private:
		int _top;
		Type * _base;
};

template <typename Type, size_t kSize>  
Stack<Type,kSize>::~Stack()
{
	delete [] _base;
}

template <typename Type, size_t kSize>  
bool Stack<Type,kSize>::empty() const
{
	return _top == -1;
}

template <typename Type, size_t kSize>  
bool Stack<Type,kSize>::full() const
{
	return _top == kSize - 1;

}

template <typename Type, size_t kSize>
void Stack<Type,kSize>::push(const Type & t )
{
	if(full())
	{
		LogInfo("stack is full.");

	}else{
		_base[++_top] = t;
	}
}

template <typename Type, size_t kSize>
void Stack<Type,kSize>::pop()
{
	if(empty())
	{
		LogInfo("stack is empyt.");
	}
	else{
			--_top;	
	}
}

template <typename Type, size_t kSize>
Type Stack<Type, kSize>::top()
{
		return _base[_top];
}


int main(void)
{
	Stack<int> stack;
	LogInfo("Stack is empty？%d",stack.empty());
	stack.push(1);
	LogInfo("Stack is empty？%d",stack.empty());

	for(size_t idx =1;idx != 12; ++idx)
	{
		stack.push(idx);
	}
	
	LogInfo("Stack is full？%d",stack.full());
	while(!stack.empty())
	{
		LogInfo("%d",stack.top());
		stack.pop();
	}
	LogInfo("Stack is empty？%d",stack.empty());

	return 0;
}
