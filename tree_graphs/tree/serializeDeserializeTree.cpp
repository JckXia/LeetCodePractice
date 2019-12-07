#include <iostream>
#include  <vector>
#include <string>
#include <list>
using namespace std;

class TreeNode {
public:
  TreeNode(int val):val{val},left{nullptr},right{nullptr}{

  }
  int val;
  TreeNode *left;
  TreeNode* right;
};

void serializeHelper(TreeNode *node,string& retVal){
  if(node==nullptr){

    return ;
  }

  string val=node->val;
  serializeHelper(node->left);
  serializeHelper(node->right);
}

string serialize(TreeNode * tree){
  string retStr="";
  return serializeHelper(tree,retStr);
}


int main(){
 TreeNode * tree=new TreeNode(20);
 tree->left=new TreeNode(8);
 tree->left->left=new TreeNode(10);
 tree->left->left->left=new TreeNode(5);
 serialize(tree);
}
