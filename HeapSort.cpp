#include <vector>
#include "heap.hpp"
#include <iostream>

using namespace std;

vector<int> Heap_Sort(vector<int>& A)
{
        HEAP heap(A, A.size());
	heap.HEAP::BUILD_MAX_HEAP(heap, heap.HEAP::GetHeapSize());	
        int heapSize = heap.GetHeapSize();

        for(int i=heap.GetLength();i>=2;i--)
        {
            heap.HEAP::exchange(i-1,0);
            heapSize--;
            heap.HEAP::SetHeapSize(heapSize);
            heap.HEAP::Max_HEAPFY(heap, 0);
         }

    return heap.A;

}

int main(void)
{

    vector<int> arr;
    int n;
    cout<<"please input number of array"<<endl;
    cin>>n;
    while(n--)
    {
       int cur;
       cin>>cur;
       arr.push_back(cur);
    
    }

    arr=Heap_Sort(arr);
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}

