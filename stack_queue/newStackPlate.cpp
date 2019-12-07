#include <iostream>
#include <vector>
using namespace std;

class DinnerPlates{
public:
   DinnerPlates(int capacity):plateCapacity{capacity}{
       vector<int> firstStk;
        plateStks.push_back(firstStk);
   }

   //Finds the first stack where the capacity isnt full
   void push(int val){
      int firstIndexForNonFullStack=-1;
      for(int i=0;i<plateStks.size();i++){
         if(plateStks[i].size()<plateCapacity){
             firstIndexForNonFullStack=i;
             break;
         }
      }
      if(firstIndexForNonFullStack != -1){
        plateStks[firstIndexForNonFullStack].push_back(val);
        return;
      }
      //Else case: Check firstIndexForNonFullStack is -1 //Not found
      vector<int> newStk;
      newStk.push_back(val);
      plateStks.push_back(newStk);
      return;
   }

  //Pop from a certain stack
   int popAtStack(int stackIndex){
       if(stackIndex >= plateStks.size() || plateStks[stackIndex].size()==0){
         return -1;
       }
       int retVal=plateStks[stackIndex].back();
        plateStks[stackIndex].pop_back();
        return retVal;
   }

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

  void debugPrint(){
     for(int i=0;i<plateStks.size();i++){
        cout<<"[";
          vector<int> plate=plateStks[i];
          for(int i=0;i<plate.size();i++){
            cout<<plate[i]<<" ";
          }
          cout<<endl;
     }
  }
 private:
  vector<vector<int>>plateStks;
  int plateCapacity;
};

int main(){
  DinnerPlates * stk=new DinnerPlates(2);
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
