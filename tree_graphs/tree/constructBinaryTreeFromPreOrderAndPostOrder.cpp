#include <vector>
#include <iostream>
#include <utility>
using namespace std;

struct TreeNode{
  TreeNode(int x):val{x},left{nullptr},right{nullptr}{

  }
  int val;
  TreeNode * left;
  TreeNode *right;
};

int getLeftChild(int index,vector<int>& arr){
   int leftChildIndex=index * 2 +1;
   if(leftChildIndex >=arr.size()){
     return -1;
   }
   return arr[leftChildIndex];
}

int getRightChild(int index,vector<int> &arr){
  int rightChildIndex=2*index+2;
   if(rightChildIndex >= arr.size()){
     return -1;
   }
   return arr[rightChildIndex];
}

TreeNode * buildTree(vector<int> & preorder,vector<int>& inorder){
   TreeNode *retNode=new TreeNode(preorder[0]);
   vector<pair<TreeNode *,int>> currNodes;
   vector<pair<TreeNode *,int>> nextNodes;
  currNodes.push_back(make_pair(retNode,0));

   while(!currNodes.empty()){
        for(auto nodePair:currNodes){
            int arrIndex=nodePair.second;
            TreeNode * curNode=nodePair.first;
             if(getLeftChild(arrIndex,preorder) != -1){
                int leftChildVal=getLeftChild(arrIndex,preorder);
                TreeNode * newTreeNode=new TreeNode(leftChildVal);
                curNode->left=newTreeNode;
               nextNodes.push_back(make_pair(curNode->left,2*arrIndex+1));
             }
             if(getRightChild(arrIndex,preorder)!=-1){
               int rightChildVal=getRightChild(arrIndex,preorder);
               TreeNode * newTreeNode =new TreeNode(rightChildVal);
               curNode->right=newTreeNode;
               nextNodes.push_back(make_pair(curNode->right,2*arrIndex+2));
             }
        }
      currNodes.swap(nextNodes);
      nextNodes.clear();
   }
   return retNode;
}
void printTree(TreeNode *tree){
  if(tree == nullptr){
    return;
  }
  printTree(tree->left);
  cout<<tree->val<<endl;
  printTree(tree->right);
}
int main(){

  vector<int> preOrder={3,9,20,15,7};
 TreeNode * retNode=buildTree(preOrder,preOrder);
  printTree(retNode);
  return 0;
}
