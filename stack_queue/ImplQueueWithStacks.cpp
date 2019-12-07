#include <iostream>
#include <stack>
using namespace std;

class MyQueue{
  public:
    MyQueue(){

    }
    //Push elem x to back of queue
    void push(int x){
      mainQueue.push(x);

    }

    //Remove the element from the front of queue
    int pop(){
       while(mainQueue.size()>1){
          tempQueue.push(mainQueue.top());
          mainQueue.pop();
       }
       int retVal=mainQueue.top();
       mainQueue.pop();

      //Restore elemnts into stack 1 from stack 2
      for(int i=0;i<tempQueue.size();i++){
         mainQueue.push(tempQueue.top());
         tempQueue.pop();
      }
       return retVal;
    }

    //Get the front element
    int peek(){
      while(mainQueue.size()>1){
         tempQueue.push(mainQueue.top());
         mainQueue.pop();
      }
      int retVal=mainQueue.top();

      for(int i=0;i<tempQueue.size();i++){
        mainQueue.push(tempQueue.top());
        tempQueue.pop();
      }
      return retVal;
    }

    //Return whether or not the queue is empty
    bool empty(){
      return mainQueue.empty();
    }
  private:
    stack<int> mainQueue;
    stack<int> tempQueue;

};

int main(){
 MyQueue queue;
 queue.push(1);
queue.push(2);

cout<< queue.peek()<<endl;  // returns 1
cout<<queue.pop()<<endl;   // returns 1
cout<< queue.empty()<<endl;
}
