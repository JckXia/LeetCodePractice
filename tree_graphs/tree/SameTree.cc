 #include <iostream>
 #include <vector>
 using namespace std;
 class TreeNode{
 public:
   TreeNode(int val):val{val},left{nullptr},right{nullptr}{  }
 int val;
 TreeNode *left;
 TreeNode *right;
 };



 bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q== nullptr){
            return true;
        }
         if(p == nullptr && q || q==nullptr &&p){
             return false;
         }
         if(p->val != q->val){
             return false;
         }
       //p->val == q->val
        bool resultLeftSubTree=isSameTree(p->left,q->left);
       bool resultRightSubTree=isSameTree(p->right,q->right);
        if(resultLeftSubTree == false || resultRightSubTree == false){
            return false;
        }
        return true;
   }

   int main(){
     TreeNode  * treeOne=new TreeNode(1);
      treeOne->left=new TreeNode(2);
     TreeNode * treeTwo=new TreeNode(1);
     treeTwo->left=new TreeNode(2);
     bool testRes=isSameTree(treeOne,treeTwo);
     cout<<testRes<<endl;
   }
