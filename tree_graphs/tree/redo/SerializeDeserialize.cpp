#include <iostream>
#include <vector>
#include <string>
using namespace std;

//  * Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Codec{
public:
  string serailize(TreeNode *root){
    string retStr="[";
     if(root==nullptr){
       return "[]";
     }
     vector<TreeNode *>curNodes;
     vector<TreeNode *>nextNodes;
     curNodes.push_back(root);

     while(!curNodes.empty()){
        string level="";
        bool checkFlag=true;
        for(auto node:curNodes){
          if(node != nullptr){
            checkFlag=false;
          }
        }
         for(auto node:curNodes){
            if(node == nullptr){

                if(checkFlag == false){
                  level=level+"null,";
                }
            }else{

            int val=node->val;
            level=level+to_string(val)+",";
            nextNodes.push_back(node->left);
            nextNodes.push_back(node->right);
          }
         }
         retStr+=level;
         curNodes.swap(nextNodes);
         nextNodes.clear();
     }
     retStr.pop_back();
     retStr+=']';
     return retStr;
  }

  TreeNode *deserailize(string data){
      char delimOne='[';
      char delimTwo=']';
      char delimThree=',';
      
  }
};


int main(){
  Codec * sol=new Codec;
  TreeNode *tree=new TreeNode(1);
  tree->left=new TreeNode(2);
  tree->right=new TreeNode(3);
  tree->right->left=new TreeNode(4);
  tree->right->right=new TreeNode(5);
  string retStr=sol->serailize(tree);
  sol->deserailize(retStr);
  //cout<<retStr<<endl;
}
