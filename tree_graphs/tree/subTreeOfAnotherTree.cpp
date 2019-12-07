#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
};

class Solution{
public:

  bool isSameTree(TreeNode *s,TreeNode *t){
    if(s == nullptr && t == nullptr){
      return true;
    }
    if(s == nullptr || t== nullptr ){
      return false;
    }
     if(s->val !== t->val){
       return false;
     }
     return s->val == t->val && isSameTree(s->left,t->left) && isSameTree(s->right,t->right);
  }

  bool isSubTree(TreeNode *s,TreeNode *t){
    if(s == nullptr && t == nullptr){
      return true;
    }
    if(s == nullptr || t== nullptr){
      return false;
    }
    if(isSameTree(s,t)){
      return true;
    }
    return isSubTree(s->left,t)||isSubTree(s->right,t);
  }
};


int main(){

}
