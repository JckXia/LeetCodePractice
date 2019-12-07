#include <iostream>
#include <list>
#include <vector>
using namespace std;



class TreeNode {
public:
  TreeNode(int val):val{val},left{nullptr},right{nullptr}{

  }
  int val;
  TreeNode *left;
  TreeNode* right;
};

  vector<vector<int>> BFS(TreeNode*root){
    if(root == nullptr){
      return {};
    }
    vector<vector<int>> retVal;
    vector<TreeNode *>curr;
    vector<TreeNode *>next;
    curr.push_back(root);
    while(!curr.empty()){
       retVal.push_back({});
       for(TreeNode *node:curr){
          ans.back().push_back(node->val);
          if(node->left){
            next.push_back(node->left);
          }
          if(node->right){
            next.push_back(node->right);
          }
       }
       curr.swap(next);
       next.clear();
    }
    return retVal;
  }

 vector<vector<int>> BFSTree(TreeNode * tree){
    TreeNode * currNode;
    list<TreeNode*>queue;
    vector<vector<int>>retVal;
     if(tree == nullptr){
       return {};
     }
    queue.push_back(tree);
    while(!queue.empty()){
      retVal.push_back({});
       currNode=queue.front();
       queue.pop_front();
          if(node->left) {
            queue.push_back(currNode->left);
          }
          if(node->right){
            queue.push_back(currNode->right);
          }
       }
    return retVal;
 }


int main(){
  TreeNode * tree=new TreeNode(4);
  tree->left=new TreeNode(14);
  tree->left->left=new TreeNode(54);
  tree->left->right=new TreeNode(57);
  tree->right=new TreeNode(50);
  tree->right->left=new TreeNode(98);
  tree->right->right=new TreeNode(100);
vector<vector<int>>traversalRes=BFSTree(tree);
  for(int i=0;i<traversalRes.size();i++){
     for(int j =0;j<traversalRes[i].size();j++){
        cout<<traversalRes[i][j]<<" ";
     }
     cout<<endl;
}
}
