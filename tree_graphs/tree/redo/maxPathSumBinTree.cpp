#include <iostream>

int maxPathSumUtil(TreeNode *root,int &currentMaxPathSum){
   if(root==nullptr){
     return 0;
   }
   int left=max(0,maxPathSumUtil(root->left,currentMaxPathSum));
   int right=max(0,maxPathSumUtil(root->right,currentMaxPathSum));
   int curSum=left+right+root->val;
   currentMaxPathSum=max(curSum,currentMaxPathSum);
   return max(left,right)+root->val;
}

int maxPathSum(TreeNode *root){
   int init=INT_MIN;
   maxPathSumUtil(root,init);
   return init;
}
