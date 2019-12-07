#include <iostream>
#include <vector>
using namespace std;

class DinnerPlates{
public:

  DinnerPlates(int capacity):plateCapacity{capacity},capacityCounter{0},currentStackIndex{0}{
      vector<int> stk;
      plateStk.push_back(stk);
  }

  void push(int val){
    if(capacityCounter == plateCapacity){
        capacityCounter=0;
        vector<int>newStk;
        newStk.push_back(val);
        plateStk.push_back(newStk);
        capacityCounter++;
        currentStackIndex++;
        return;
    }
    for(int i =0;i<plateStk.size();i++){
         if(plateStk[i].size() < plateCapacity){
               plateStk[i].push_back(val);
               return;
         }
    }
    capacityCounter++;
  }

  int pop(){
    //Current stack is empty
    if(plateStk[currentStackIndex].size()==0){
      currentStackIndex--;
      int retVal= plateStk[currentStackIndex].back();
      plateStk[currentStackIndex].pop_back();
      return retVal;
    }
    int retVal=plateStk[currentStackIndex].back();
    plateStk[currentStackIndex].pop_back();
    return retVal;
  }

  int popAtStack(int index){

      if(plateStk[index].size() ==0){

        return -1;
      }
    int retVal=plateStk[index].back();
      plateStk[index].pop_back();
     return retVal;
  }
 
   vector<vector<int>> plateStk;
  const int plateCapacity;
    int currentStackIndex;
    int capacityCounter;
};

int main(){
  DinnerPlates* plateStk=new DinnerPlates(2);
  plateStk->push(1);
  plateStk->push(2);
  plateStk->push(3);
  plateStk->push(4);
  plateStk->push(5);
  cout<<plateStk->popAtStack(0)<<endl;
  plateStk->push(20);
  plateStk->push(21);
  cout<<plateStk->popAtStack(0)<<endl;
  cout<<plateStk->popAtStack(2)<<endl;

}
