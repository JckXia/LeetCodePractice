#include <iostream>
#include <vector>
using namespace std;

bool isSameTree(TreeNode *p,TreeNode *q){
  if(p == nullptr && q == nullptr){
    return true;
  }
  if(p && q==nullptr || q && p == nullptr){
    return false;
  }
  bool checkLeftTree=isSameTree(p->left,q->left);
  bool checkRightTree=isSameTree(p->right,q->right);
  return checkLeftTree&&checkRightTree;
}
