#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
      int val;
     TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool isValidBST(TreeNode* root) {
      if(root == nullptr){
          return true;
      }
       if(root->left == nullptr && root->right ==nullptr){
           return true;
       }
       if (root->left && root->right ==nullptr){
          if(root->val <= root->left->val){
              return false;
          }
          return true;
       }
       if (root->right&& root->left ==nullptr){
          if(root->val >= root->right->val){
              return false;
          }
          return true;
       }

      if(root->left->val >= root->val || root->right->val <= root->val){
          return false;
      }

       return isValidBST(root->left) && isValidBST(root->right);
   }

   int main(){
     TreeNode * node=new TreeNode(2);
     node->right=new TreeNode(1);
      bool check=isValidBST(node);
      cout<<check<<endl;
   }
