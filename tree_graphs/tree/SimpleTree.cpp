#include <iostream>
#include <vector>
using namespace std;

class BinaryNode{
public:
   BinaryNode(int val):data{val},left{nullptr},right{nullptr}{
   }
   ~BinaryNode(){
     delete left;
     delete right;
   }
   BinaryNode *left;
   BinaryNode *right;
   int data;
};

int main(){
 BinaryNode * tree=new BinaryNode(2);
  tree->left=new BinaryNode(4);
  tree->right=new BinaryNode(5);
  tree->left->right=new BinaryNode(10);
  cout<<tree->left->data<<endl;
  delete tree;
}
