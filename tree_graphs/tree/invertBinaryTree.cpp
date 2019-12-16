#include <iostream>
#include <vector>

TreeNode * invertTree(TreeNode *root){
  if(root == nullptr){
    return nullptr;
  }
  TreeNode *temp=invertTree(root->left);
  root->left=invertTree(root->right);
  root->right=invertTree(root->left);
  return root;
}
