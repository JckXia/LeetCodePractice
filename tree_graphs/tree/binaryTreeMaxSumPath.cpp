#include <iostream>
#include <list>
#include <climits>
#include <algorithm>
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

int maxPathSumHelper(TreeNode  * root,int& currentMaxPathVal){
   if(root == nullptr){
     return 0;
   }
  if(root->left == nullptr && root->right == nullptr){
    return root->val;
  }
  //Get the max from the left subtree (May have negative val, compare it with 0)
   int leftSubTreeVal=max(0,maxPathSumHelper(root->left,currentMaxPathVal));

   //Get the max from right subtree (May also have negative value, compare it with 0)
   int rightSubTreeVal= max(0,maxPathSumHelper(root->right,currentMaxPathVal));

   //Maximize the traversal by including current node ()
    int sum=leftSubTreeVal+rightSubTreeVal+root->val;

    //Ensure currentMaxPathVal is the largest value when compared
    //with the sum calculated above
    currentMaxPathVal=max(currentMaxPathVal,sum);

    //Return the maximum of the two and add it to the root value?
    return max(leftSubTreeVal,rightSubTreeVal)+root->val;
}
int maxPathSum(TreeNode * root){
   int init=INT_MIN;
   maxPathSumHelper(root,init);
   return init;
}

int main(){
  TreeNode * tree=new TreeNode(1);
  tree->left=new TreeNode(2);
  tree->right=new TreeNode(3);
  int res=maxPathSum(tree);
  cout<<res<<endl;
}
