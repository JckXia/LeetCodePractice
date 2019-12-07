#include <iostream>
#include <stack>

class MyQueue {
public:
  MyQueue(){

  }
  void push(int x){
      mainQueue.push(x);
  }
  int pop(){
     //If the mainQueue is empty, return -1;
     if(mainQueue.empty()){
       return -1;
     }

     //Pop one item from the top of the stack
     int x=mainQueue.top();
     mainQueue.pop();

    //If the stack becomes empty, return the popped item.
    //(We have reached the base case where theres only item in the stack)
     if(mainQueue.empty()){
       return x;
     }

     //Else, recursively pop the items off the stack
     int item=pop();

     //Push popped item back to stack
     mainQueue.push(x);

     //Return result of pop call
     return item;
  }

  int peek(){
     //If the mainQueue is empty, there are no elements=> return -1
     if(mainQueue.empty()){
        return -1;
     }
     int x=mainQueue.top();
     if(mainQueue.size() == 1){
       return x;
     }

     int item=peek();

     mainQueue.push(x);

     return item;
  }

  bool empty(){
    return mainQueue.empty();
  }
private:
  stack<int> mainQueue;

};

int main(){
  MyQueue queue;
  queue.push(1);
  queue.push(2);
  cout<<queue.peek()<<endl;
  cout<<queue.pop()<<endl;
  cout<<queue.empty()<<endl;
}
