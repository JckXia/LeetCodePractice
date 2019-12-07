#include <iostream>
#include <vector>
#include<list>
using namespace std;


class TreeNode{
public:
  TreeNode(int val):val{val},left{nullptr},right{nullptr}{  }
int val;
TreeNode *left;
TreeNode *right;
};


void buildLinkedListsForDepthOfTreesHelper(TreeNode * tree,vector<list<int>>depthList,int level){
    if(tree == nullptr){
      return;
    }
    
}

TreeNode * buildLinkedListsForDepthOfTrees(TreeNode *tree){

   vector<list<int>>depthList;
   buildLinkedListsForDepthOfTreesHelper(tree,depthList,0);
   return tree;
}




int main(){

}
