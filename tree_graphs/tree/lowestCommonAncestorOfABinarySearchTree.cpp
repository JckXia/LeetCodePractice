#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  TreeNode(int x):val{x},left{nullptr},right{nullptr}{}
  int val;
  TreeNode *left;
  TreeNode *right;
};

TreeNode * lowestCommonAncestor(TreeNode *root,TreeNode *s,TreeNode *p){
   if(root == nullptr){
     return nullptr;
   }
  if(root->left && root->right){
    TreeNode *checkLeftNode=lowestCommonAncestor(root->left,s,p);
    TreeNode *checkRightNode=lowestCommonAncestor(root->right,s,p);
     if(root->val == s->val){
         if(checkLeftNode&&checkLeftNode->val == p->val ||checkRightNode&&checkRightNode->val == p->val){
           return root;
         }
         return nullptr;
     }
     if(root->Val == p->val){
        if(checkLeftNode&& checkLeftNode->val == s->val || checkRightNode&&RcheckRightNode->val == s->val){
          return root;
        }
        return nullptr;
     }
     if(checkLeftNode&&checkRightNode && (checkLeftNode->val == s->val &&checkRightNode->val == p->val ||
                                          checkLeftNode->val == p->val&&checkRightNode->val == s->val)) {
        return root;
     }
     return nullptr;
  }
  //Left root is non empty, right root is empty
  if(root->left){
      TreeNode *checkNodes=lowestCommonAncestor(root->left,s,p);
      if(root->val == s->val){
          if(checkNodes->val == p->val){
            return root;
          }
          return nullptr;
      }
      if(root->val == p->val){
        if(checkNodes->val == s->val){
          return root;
        }
      }
      return nullptr;
  }
  if(root->right){
    TreeNode *checkNodes=lowestCommonAncestor(root->root,s,p);
    if(root->val == s->val){
        if(checkNodes->val == p->val){
          return root;
        }
        return nullptr;
    }
    if(root->val == p->val){
      if(checkNodes->val == s->val){
        return root;
      }
    }
    return nullptr;
  }
  return nullptr;
}

int main(){
 TreeNode *tree=new TreeNode(6);
 tree->left=new TreeNode(2);
 tree->right=new TreeNode(8);
 tree->left->left=new TreeNode(0);
 tree->left->right=new TreeNode(4);

}
