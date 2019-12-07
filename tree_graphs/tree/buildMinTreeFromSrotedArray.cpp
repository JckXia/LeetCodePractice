#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
public:
  TreeNode(int val):val{val},left{nullptr},right{nullptr}{

  }
  ~TreeNode(){
    delete left;
    delete right;
  }
  TreeNode *left;
  TreeNode *right;
  int val;
};

class convertArrayToTree{
public:
  convertArrayToTree():tree{nullptr}{
    cout<<"Function created!"<<endl;
  }
  ~convertArrayToTree(){
    delete tree;
  }

  TreeNode* buildTree(vector<int> array){
      if(array.size() ==0){return nullptr;}
      if(array.size() ==1){
          int val=array[0];
          TreeNode * newNode=new TreeNode(val); //Created newNode;
          return newNode;
      }
      int midPointIndex=array.size()/2;
      TreeNode * newNode=new TreeNode(array[midPointIndex]);

      vector<int> leftSubArray(array.begin(),array.begin()+midPointIndex);
      newNode->left=buildTree(leftSubArray);
      //No extra right elements
      if(midPointIndex+1==array.size()){
          vector<int> emptyArray={};
          newNode->right=buildTree(emptyArray);
      }else{
        vector<int>rightSubArray(array.begin()+midPointIndex+1,array.end());
        newNode->right=buildTree(rightSubArray);
      }
      return newNode;
  }

  TreeNode * getTree(){
    return tree;
  }

  vector<int> sortedArray={1,4,9 };
  TreeNode * tree;
};

int main(){
  //print *(array._M_impl._M_start)@array.size()

  convertArrayToTree * convertTree=new convertArrayToTree();
  TreeNode * bst= convertTree->buildTree(convertTree->sortedArray);

   delete convertTree;
}
