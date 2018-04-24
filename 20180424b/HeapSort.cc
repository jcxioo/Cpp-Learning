 ///
 /// @file    HeapSort.cc
 /// @author  jcx(yxjcxstack@gmail.com)
 /// @date    2018-04-24 09:14:03
 ///
 
#include <iostream>
using std::cout;
using std::endl;

template <typename T, typename Compare = std::less<T>>
class HeapSort
{
	public:

		HeapSort(T * arr, int size)
		{
			for(int i = size/2; i > 0; i--)
			{
				heapAdjust(arr,i,size);
			}
		}
		void heapAdjust(T * arr, int i, int size)
		{
			
		}
		void sort();
	private:
		T * arr;

};

void test0()
{
//	int arr = {1,4,2,22,33,44,13,32};

}

int main()
{
	test0();
	return 0;
}
