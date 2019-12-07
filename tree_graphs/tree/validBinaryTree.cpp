#include <iostream>
#include <vector>
#include <climits>
using namespace std;
struct TreeNode{
  TreeNode(int x):val{x},left{nullptr},right{nullptr}{}
  int val;
  TreeNode *left;
  TreeNode *right;
};

bool isValidBSTHelper(TreeNode *node,int min,int max){
   if(node == nullptr){
     return true;
   }
   if(node->val <= min || node->val >=max){
     return false;
   }
   return isValidBSTHelper(node->left,min,node->val) && isValidBSTHelper(node->right,node->val,max);
}

bool isValidBST(TreeNode * tree){
 return isValidBSTHelper(tree,INT_MIN,INT_MAX);
}

int main(){
  TreeNode * node=new TreeNode(4);
  node->left=new TreeNode(2);
  node->right=new TreeNode(0);
  bool check=isValidBST(node);
  cout<<check<<endl;
}
