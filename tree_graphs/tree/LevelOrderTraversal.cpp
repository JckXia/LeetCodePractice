#include <iostream>
#include <vector>
using namespace std;

class TreeNode{
public:
   TreeNode(int val):val{val},left{nullptr},right{nullptr}{

   }
  ~TreeNode(){
    delete left;
    delete right;
  }

   int val;
   TreeNode *left;
   TreeNode *right;
};

void levelOrderPrintHelper(TreeNode *tree){
    if(tree == nullptr){
      return;
    }
    if(tree->left && tree->right){
        cout<<tree->left->val<<" "<<tree->right->val<<" "<<endl;  //Print the value at the left and right nodes
        levelOrderPrintHelper(tree->left);
        levelOrderPrintHelper(tree->right);
    }
}

void levelOrderPrint(TreeNode *tree){
   cout<<tree->val<<endl;
   levelOrderPrintHelper(tree);
}

int main(){
  TreeNode * tree=new TreeNode(3);
   tree->left=new TreeNode(4);
   tree->left->left=new TreeNode(5);
   tree->left->right=new TreeNode(14);

   tree->right=new TreeNode(190);
   tree->right->left=new TreeNode(14);
   tree->right->right=new TreeNode(19);
  levelOrderPrint(tree);
}
