#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DinnerPlates{
public:
   DinnerPlates(int capacity):capacity{capacity}{

      vector<int> subStack;
      plateStks.push_back(subStack);
   }
  void push(int val){
    //If the stack vector isnt full
     if(lastNonFullSubStackIndexVec.size()==0){
        //Check if current top of stack is Empty
        if(plateStks[plateStks.size()-1].size() < capacity){
           plateStks[plateStks.size()-1].push_back(val);
           return;
        }
        //Case where it has reached the max capacity, we need a enw stack
        vector<int>newStk;
        newStk.push_back(val);
        plateStks.push_back(newStk);
        return;
     }else{
       //Sort this array
        sort(lastNonFullSubStackIndexVec.begin(),lastNonFullSubStackIndexVec.end(),greaterThan);
        int leftMostStackIndex=lastNonFullSubStackIndexVec.back();
         lastNonFullSubStackIndexVec.pop_back();
         plateStks[leftMostStackIndex].push_back(val);
         return;
     }
  }

 //Pop removes the rightmost non empty stack and removes it from that stack
  int pop(){
    int topOfPlateStk=plateStks.size()-1;
    while(topOfPlateStk >=0){
       if(plateStks[topOfPlateStk].size() ==0){
         topOfPlateStk--;
       }else{
          int retVal=plateStks[topOfPlateStk].back();
           plateStks[topOfPlateStk].pop_back();
           return retVal;
       }
    }
    return -1;
  }

  int popAtStack(int stackIndex){
    if(stackIndex >= plateStks.size() || plateStks[stackIndex].size()==0){
      return -1;
    }
    int retVal=plateStks[stackIndex].back();
    plateStks[stackIndex].pop_back();
    lastNonFullSubStackIndexVec.push_back(stackIndex);
    return retVal;
  }

 private:
   static bool greaterThan(int a,int b){
     return a>b;
   }
   vector<vector<int>> plateStks;
   vector<int> lastNonFullSubStackIndexVec;

   const int capacity;
};

int main(){
 stackPlate * stk=new stackPlate(2);
 stk->push(1);
 stk->push(2);
 stk->push(3);
 stk->push(4);
 stk->push(5);

 cout<<stk->popAtStack(0)<<endl;
 stk->push(20);
 stk->push(21);

 cout<<stk->popAtStack(0)<<endl;
 cout<<stk->popAtStack(2)<<endl;

 cout<<"Final steps"<<endl;
  cout<<stk->pop()<<endl;
   cout<<stk->pop()<<endl;
    cout<<stk->pop()<<endl;
     cout<<stk->pop()<<endl;
      cout<<stk->pop()<<endl;
}
