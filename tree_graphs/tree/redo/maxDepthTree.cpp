#include <iostream>
#include <vector>
using namespace std;

int maxDepth(TreeNode* root) {
    if(root == nullptr){
        return 0;
    }
    int leftMaxVal=maxDepth(root->left);
    int rightMaxVal=maxDepth(root->right);
    if(leftMaxVal < rightMaxVal){
        return 1+rightMaxVal;
    }
    return leftMaxVal+1;
}

int main(){

}
