#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Stack{
public:
   Stack(){

   }
   void push(int x){
    mainStack.push(x);
   }
   int pop(int x){
      int retVal=mainStack.back();
      mainStack.pop();
      return retVal;
   }
   void sortStack(){

     //While the temp stack is 
     while(tempStack.empty() == false && tempStack.top()>temp){
        int tempVal=mainStack.top();mainStack.pop();
        int val=tempStack.top();tempStack.pop();
        mainStack.push(val);
        tempStack.push(tempVal);
     }
   }

 private:
  stack<int> mainStack;
  stack<int> tempStack;
};
