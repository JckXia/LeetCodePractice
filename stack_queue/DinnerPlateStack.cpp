#include <iostream>
#include <set>
#include <vector>
#include <stack>
using namespace std;

class DinnerPlates{
public:
  DinnerPlates(int capacity):capacity{capacity}{

  }
  void push(int val){
      //Check if there are any availlable stacks.
      //Ifnot, create a stack and push it to the plateStacks
      //Insert the stack index into the set
    if(stk_aval.empty()){
      plateStks.push_back(stack<int>());
      stk_aval.insert(plateStks.size()-1);
    }
    //If there are availlable plateStack
    //Get the firstAvaillableIndex from the BST set
    //Push the value onto the BST at plateStks[firstAvaillableIndex]
    //If we have then reached the capacity, remove the recent index
    //from the stk_aval set(BST)
    auto firstAvaillableIndex=*stk_aval.begin();
    plateStks[firstAvaillableIndex].push(val);
    if(plateStks[firstAvaillableIndex].size() == capacity){
        stk_aval.erase(firstAvaillableIndex);
    }
  }

  int pop(){
    //Case 1: If there are no plate stacks, then return -1
     if(plateStks.empty()){
       return -1;
     }
     //Save the value from the top of the last stack
     auto retVal=plateStks.back().top();
     plateStks.back().pop();

    //While the plate stacks aren't empty
    //and the last stack from the plate stacks
    //Isnt empty,remove the empty stacks from the plateStks
    //(Creates obstruction)
     while(!plateStks.empty() && plateStks.back().empty()){
        stk_aval.erase(plateStks.size()-1);
        plateStks.pop_back();
     }
  }

  //Pop element, put the stack index into s_aval
  int popAtStack(int index){
    if(plateStks.size()<=index || plateStks[index].empty()){
      return -1;
    }
    if(plateStks.size()-1 == index){
      return pop();
    }
    auto res=plateStks[index].top();
    plateStks[index].pop();
    stk_aval.insert(index);
    return res;
  }

private:
  vector<stack<int>> plateStks;
  set<int>stk_aval;
  int capacity;
}
