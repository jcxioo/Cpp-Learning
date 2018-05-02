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
		:_arr(arr)
		,_size(size)
		{
			cout << "HeapSort()" << endl;
			for(int i = _size/2-1; i >= 0; i--)
			{
				heapAdjust(i,_size);
			}
		}
		void heapAdjust(int i ,int length)
		{
			//cout << "heapAdjust()" << endl;
			T temp = _arr[i];//存下当前调整节点
			Compare compare;
			for(int j = i*2+1; j < length; j=j*2+1)
			{
				if(j < length-1 && compare( _arr[j], _arr[j+1]))
//				if(j<length -1 && _arr[j]<_arr[j+1])
				{
					++j;//确定左右子节点中较大的
				}
				if(!compare(_arr[j] , temp))
			//	if(_arr[j]>temp)
				{
					_arr[i] = _arr[j];//将子节点中较大的赋给父节点
					i = j;//指向子节点，继续调整
				}else{
					break;
				}
			}
			_arr[i] = temp;	
		}
		void sort()
		{
			for(int k = _size -1; k > 0; --k)
			{
				swap(0,k);
				heapAdjust(0,k);
			}
		}
		void swap(int a, int b)
		{
			T temp = _arr[a];
			_arr[a] = _arr[b];
			_arr[b] = temp;
		}
	private:
		T * _arr;
		int _size;
};
void test0()
{
	int arr[8] = {11,112,114,10,12,14,16,18};
	HeapSort<int> heap(arr,8);
	heap.sort();
	for(int idx = 0; idx < 8;++idx)
	{
		cout << arr[idx] << endl;
	}
}

int main()
{
	test0();
	return 0;
}
