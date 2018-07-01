#include <iostream>
#include <vector>
/* a class for maintainence  HEAP and building HEAP*/
/*AUTHOR LIQING*/
using namespace std;

class HEAP{
   private:
       int heapSize=0;
       int heapLength=0;  
   public:
       vector<int> A;
       HEAP(){}
       HEAP(vector<int> arr, int heapsize):A(arr), heapSize(heapsize){}
       void Max_HEAPFY(HEAP& heap, int i);
       int LEFT(int i);
       int RIGHT(int i);
       void BUILD_MAX_HEAP(HEAP& A, int num);
       int GetHeapSize(){ return heapSize;}
       int GetLength(){return heapLength=A.size();}
       int operator[](unsigned int i)
	{
	  return A.at(i); 
	}        
          
       void exchange(int i, int j){
           int cur= A[i];
           A[i]= A[j];
           A[j]=cur;
	}    
       void SetHeapSize(int size)
      {
	heapSize=size;

      }
              
};



//maintain a max_heap
void HEAP::Max_HEAPFY(HEAP& heap, int i)
{

    int largest=i;
    int l= LEFT(i);
    int r= RIGHT(i);
    
    if(l<heap.GetHeapSize() && heap[l]>heap[i])
    {
    
          largest= l;
    
    }
    
    
    if(r<heap.GetHeapSize() && heap[r]>heap[largest])
    {
    
         largest= r;
    
    
    }
    
    if(largest!=i)
    {
        exchange(i,largest);
        HEAP::Max_HEAPFY(heap, largest);

    }
    
}


int HEAP::LEFT(int i)
{
	return 2*i+1;
}


int HEAP::RIGHT(int i)
{

	return 2*i+2;
}


//build a  heap
void HEAP::BUILD_MAX_HEAP(HEAP& A, int num)
{
    int heap_size=A.HEAP::GetHeapSize();
    
    for(int i=heap_size/2; i>=0; i--)
    {
        HEAP::Max_HEAPFY(A,  i);
    }

}



