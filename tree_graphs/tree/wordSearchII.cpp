#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;
const int NUM_OF_ALPHABETS=26;

class Trie {
public:
   struct TrieNode{
       struct TrieNode *children[26];

       bool isEndOfWord;
   };

   struct TrieNode * getNode(){
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
   /** Initialize your data structure here. */
   Trie() {
       //Create trie
       head=getNode();
   }

   /** Inserts a word into the trie. */
   void insert(string word) {
       TrieNode *temp=head;
       for(auto ch:word){
           char c=ch;
           if(temp->children[getCharOffSet(ch)]==nullptr){
              temp->children[getCharOffSet(ch)]=getNode();
           }
           temp=temp->children[getCharOffSet(ch)];
       }
       temp->isEndOfWord=true;
   }

     /** Returns if there is any word in the trie that starts with the given prefix. */
   bool startsWith(string prefix) {
       TrieNode *temp=head;
       for(auto ch : prefix){
           if(temp->children[getCharOffSet(ch)]==nullptr){
               return false;
           }
           temp=temp->children[getCharOffSet(ch)];
       }
      return true;
   }

   /** Returns if the word is in the trie. */
   bool search(string word) {
     TrieNode *temp=head;
       for(auto ch : word){
           if(temp->children[getCharOffSet(ch)]==nullptr){
               return false;
           }
           temp=temp->children[getCharOffSet(ch)];
       }
           if(temp->isEndOfWord){
                return true;
          }
             return false;
   }

   TrieNode *head;
};

class Solution{
public:

  Solution(){
    //Creates a trie structure
    trieStruct=new Trie();
  }

char moveLeft(vector<vector<char>> &board,pair<int,int> &cord){
    vector<char> boardRow=board[cord.first];
    int yCord=cord.second;
    if(yCord == 0){
      return '#';
    }
    cord.second=yCord-1;
    return board[cord.first][cord.second];
}

char moveRight(vector<vector<char>> &board,pair<int,int> &cord){
   vector<char>boardRow=board[cord.first];
   int yCord=cord.second;
   if(yCord == boardRow.size()-1){
     return '#';
   }
   cord.second=yCord+1;
   return board[cord.first][cord.second];
}

char moveUp(vector<vector<char>> &board,pair<int,int> &cord){
   int xCord=cord.first;
   if(xCord ==0){
     return '#';
   }
   cord.first=xCord-1;
   return board[cord.first][cord.second];
}
char moveDown(vector<vector<char>> &board,pair<int,int> &cord){
   int xCord=cord.first;
   if(xCord == board.size()-1){
      return '#';
   }
   cord.first++;
   return board[cord.first][cord.second];
}

vector<string> findWords(vector<vector<char>> &board,vector<string>&words){
   for(auto word:words){
     trieStruct->insert(word);
   }
   cout<<"Successfully inserted the word"<<endl;

}
Trie * trieStruct;

};

int main(){
   Solution * sol=new Solution();
   vector<vector<char>> board={{'a','b','c'},{'d','e','f'}};
   vector<string> words={"oath","pen","eat","rain"};
 
    sol->findWords(board,words);

}
