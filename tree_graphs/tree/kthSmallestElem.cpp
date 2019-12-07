#include <iostream>
#include <vector>
#include <list>
using namespace std;

struct TreeNode {
  TreeNode(int x):val{x},left{nullptr},right{nullptr}{}
  int val;
  TreeNode *left;
  TreeNode *right;
};

void binaryTreeTraversal(TreeNode *tree){
   list<TreeNode*>currNodes;
   list<TreeNode*>nextNodes;
   currNodes.push_back(tree);
   while(!currNodes.empty()){
 
      for(TreeNode * node:currNodes){
        cout<<node->val<<endl;

          if(node->left){
            nextNodes.push_back(node->left);
          }
          if(node->right){
            nextNodes.push_back(node->right);
          }
      }
      currNodes.swap(nextNodes);
      nextNodes.clear();
   }
}

int main(){
  TreeNode * tree=new TreeNode(5);
  tree->left=new TreeNode(3);
  tree->right=new TreeNode(6);
  tree->left->left=new TreeNode(2);
  tree->left->right=new TreeNode(4);
  tree->left->left->left=new TreeNode(1);
  binaryTreeTraversal(tree);
}
