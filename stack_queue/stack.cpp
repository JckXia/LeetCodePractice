#include <iostream>
using namespace std;

class Stack{
public:
   Stack(){
     cout<<"Construct stack"<<endl;
   }
   ~Stack(){
     cout<<"Delete stack"<<endl;
   }
   void push(){

   }
   void pop(){

   }
   void top(){

   }
   int size(){

   }
   bool isEmpty(){

   }
private:

   class StackNode{
      StackNode(int val){

      }
      ~StackNode(){
          delete next;
      }
      StackNode *next;
   };
   StackNode * head;
};

int main(){
  Stack * newStack=new Stack();
  delete newStack;
}
