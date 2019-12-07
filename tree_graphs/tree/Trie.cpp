#include <iostream>
#include <vector>
using namespace std;
const int ALPHABET_SIZE=26;
struct TrieNode{
   struct TrieNode *children[ALPHABET_SIZE];

   bool isEndOfWord;
};

struct TrieNode * getNode(){
    TrieNode *pNode=new TrieNode;
    pNode->isEndOfWord=false;
    for(int i=0;i<ALPHABET_SIZE;i++){
      pNode->children[i]=nullptr;
    }
    return pNode;
}

int getCharOffSet(char c){
   return c-'a';
}

void insert(TrieNode *node,string word){
   for(auto ch:word){
     char c=ch;
      if(node->children[getCharOffSet(c)] == nullptr){
         node->children[getCharOffSet(c)]=getNode();
      }
      //node->children[getCharOffSet(c)] is not null
      node=node->children[getCharOffSet(c)];
   }
    node->isEndOfWord=true;
}

bool search(TrieNode *node,string word){
  for(auto ch:word){
    char c=ch;
    if(node->children[getCharOffSet(c)] == nullptr){
      return false;
    }
    node=node->children[getCharOffSet(c)];
  }
  if(node->isEndOfWord){
    return true;
  }
  return false;
}

bool startsWith(TrieNode* node,string prefix){
  for(auto ch:prefix){
     if(node->children[getCharOffSet(ch)] == nullptr){
       return false;
     }
     node=node->children[getCharOffSet(ch)];
  }
  return true;
}



int main(){
  TrieNode *head=getNode();
  insert(head,"loopio");
  cout<<search(head,"loopio")<<endl;
  cout<<startsWith(head,"loo")<<endl;
  cout<<startsWith(head,"lo")<<endl;
  cout<<startsWith(head,"loopiod")<<endl;
}
