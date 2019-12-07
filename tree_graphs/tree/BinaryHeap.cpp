#include <iostream>
#include <vector>
#include<climits>
using namespace std;


//Change up the appraoch
//Use an array/vector to
//replicate the actions of a heap
class BinHeap{
public:
  BinHeap(){

  }

  int getParentIndex(int index){
    return (index-1)/2;
  }
  int getLeftChildIndex(int index){
    return (2*index)+1;
  }

  int getRightChildIndex(int index){
    return (2*index)+2;
  }

  int getMin(){

  }
  int extractMin(){
    if(heap.size()==0){
      return INT_MAX;
    }
    if(heap.size()==1){
       int retVal=heap[0];
       heap.pop_back();
       return retVal;
    }
    int savedValue=heap[0];
    heap[0]=heap[heap.size()-1];
    MinHeapify(0);
  }

  void MinHeapify(int index){
      int left=getLeftChildIndex(index);
      int right=getRightChildIndex(index);
      int small=index;
      if(left< heap.size() )
  }
  void insert(int val){
    //First inser the new key at the end
    heap.push_back(val);
    //This index points to the last element from the heap
    int index=heap.size()-1;

    //While index doesnt point to 0, and
    //The parent index is bigger than its child
    while(i!=0 && heap[getParentIndex(index)]>heap[index]){
         int temp=heap[getParentIndex(index)];
         heap[getParentIndex(index)]=heap[index];
         heap[index]=temp;
         i=getParentIndex(index);
    }
  }


  int pop(){

  }
private:
  vector<int> heap;
}

int main(){

}
