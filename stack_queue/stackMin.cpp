#include <iostream>
#include <utility>
#include <vector>
using namespace std;

class MinStack {
public:

    MinStack() {

    }

    void push(int x) {
        if(stack.size() == 0){
            minEle=x;
        }
         if(x < minEle){
            stack.push_back(make_pair(x,minEle));
            minEle=x;
            return;
         }

        stack.push_back(make_pair(x,minEle));
    }

    void pop() {
        pair<int,int> stackTop=stack.back();
        if(stackTop.first == minEle){
            minEle=stackTop.second;
        }
        stack.pop_back();
    }

    int top() {
      pair<int,int> a=stack.back();
        return a.first;
    }

    int getMin() {
        return minEle;
    }
private:
vector<pair<int,int>>stack;
     int minEle;
};

int main(){
  MinStack minStack;
  minStack.push(5);
  minStack.push(0)
  cout<<minStack.top()<<endl;
  cout<<minStack.getMin()<<endl;

}
