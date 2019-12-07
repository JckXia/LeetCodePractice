#include <iostream>
#include <cstdlib>
using namespace std;

#define SIZE 10

template <class item>

class Stack{
public:
  Stack(int size = SIZE);
  void push(item);
  item pop();
  item peak();
  int size();
  bool isEmpty();
  bool isFull();
  ~Stack(){
    delete [] arr;
  }
private:
  item * arr;
  int top;
  int capacity;
};

//Stack constructor
template<class item>
Stack<item>::Stack(int size){
    arr=new item[size];
    capacity=size;
    top=-1;
}

template<class item>
void Stack<item>::push(item val){
    cout<<"Inserting "<<val<<endl;
    arr[++top]=val;
}

template<class item>
item Stack<item>::peak(){
   if(!isEmpty){
     return arr[top];
   }
   return -1;
}

int main(){
   Stack<int> pt(2);

}
