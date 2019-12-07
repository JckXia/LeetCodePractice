#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int NUM_OF_ALPHABETS=26;

class WordDictionary{
public:
  struct TrieNode{
    struct TrieNode *children[NUM_OF_ALPHABETS];
    bool isEndOfWord;
  };
  struct TrieNode *getNode(){
     TrieNode *pNode=new TrieNode();
     pNode->isEndOfWord=false;
     for(int i=0;i<26;i++){
       pNode->children[i]=nullptr;
     }
     return pNode;
  }
  int getCharOffSet(char c){
    return c-'a';
  }
  WordDictionary(){
    head=getNode();
  }
  void addWord(string word){
     TrieNode *temp=head;
     for(auto ch:word){
       if(temp->children[getCharOffSet(ch)] == nullptr){
         temp->children[getCharOffSet(ch)]=getNode();
       }
       temp=temp->children[getCharOffSet(ch)];
     }
     temp->isEndOfWord=true;
  }


  bool find(TrieNode *node,string word,int index){
    if(index == word.length()){
       return node->isEndOfWord;
    }
    char c=word[index];
    if(c == '.'){
      for(int i=0;i<26;i++){
        if(node->children[i] != nullptr && find(node->children[i],word,index+1)){
           return true;
        }

      }
        return false;
    }else{
      return node->children[getCharOffSet(c)] != nullptr && find(node->children[getCharOffSet(c)],word,index+1);
    }
  }

  bool search(string word){
      TrieNode *temp=head;
      return find(temp,word,0);
  }
  TrieNode *head;
};

int main(){
 WordDictionary *dictObject=new WordDictionary();
 dictObject->addWord("a");
 dictObject->addWord("a");

 cout<<dictObject->search("a")<<endl;
cout<<dictObject->search("aa")<<endl;
 cout<<dictObject->search(".a")<<endl;
 cout<<dictObject->search("a.")<<endl;
}
