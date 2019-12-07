#include <iostream>
#include <vector>
using namespace std;

TreeNode * buildTree(vector<int> &preOrder,vector<int>&inOrder){
  if(preOrder.empty()){return NULL;}
  return build(0,inOrder.size()-1,preOrder,inOrder,0);
}

TreeNode* build(int begin,int end,vector<int>& preOrder,vector<int>& inOrder,int preStart){
  if(begin > end){
    return nullptr;
  }
  int breakIndex=find(inOrder.begin(),inOrder.end(),preOrder[preStart])-inOrder.begin();
  TreeNode * newNode=new TreeNode(preOrder[preStart]);
  newNode->left=build(begin,breakIndex-1,preOrder,inOrder,preStart+1);
  //Breakindex subtract begin to get the length of the left subtree, then we add it to the prestart. Considering the next one is
  //left node, add one
  newNode->right=build(breakIndex+1,end,preOrder,inOrder,breakIndex-begin+preStart+1);
  return newNode;
}


int main(){

}
