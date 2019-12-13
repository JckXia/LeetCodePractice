#include <iostream>
#include <vector>
using namespace std;

//The x and y coordinates stand for coordinates
//of the board
//D represents depth?

bool out_of_bound(vector<vector<char>> &board,int x,int y){
   if(x < 0 || x >= board.size()){
     return false;
   }
   if(y <0 || y>board[x].size()){
     return false;
   }
 return true;
}

bool search(vector<vector<char>> &board, int x,int y,int d,string word){
  if(out_of_bound(board,x,y)){
    return false;
  }
  if(word[d] != board[y][x]){
    return false;
  }
  if(d == word.length()-1){
    return true;
  }
  return search(board,x-1,y,d+1,word) || search(board,x+1,y,d+1,word) ||
         search(board,x,y-1,d+1,word) || search(board,x,y+1,d+1,word);
}

bool exist(vector<vector<char>>&board,string word){
     for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            if(search(board,i,j,0,word)){
              return true;
            }
        }
     }
     return false;
}

int main(){
    string word="aa";
    vector<vector<char>> board={{'a','a'},{'b','c'}};
    cout<<exist(board,word)<<endl;
}
