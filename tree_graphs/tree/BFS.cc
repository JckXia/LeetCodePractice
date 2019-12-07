#include<iostream>
#include <list>

using namespace std;
class Graph{
public:
   Graph(int v):verticeCount{v}{
     adj=new list<int>[verticeCount];
   }

   void addEdge(int v,int w){
       adj[v].push_back(w);  //Add w to be a neighbour of v
   }
    //Start from a certain a vertex
   void BFS(int s){
     bool *visited=new bool[verticeCount];
     for(int i=0;i<verticeCount;i++){
        visited[i]=false;
     }
     list<int> queue; //Create a queue for BFS
      list<int>::iterator i;
     //Mark current node as visited
     visited[s]=true;
     queue.push_back(s);

    while(!queue.empty()){
        s=queue.front();
        cout<<s<<" ";
        queue.pop_front();
        for(i=adj[s].begin();i!=adj[s].end();++i){

          //If the vertices havernt been visited, push it to the
          //Queue, mark the node as visited
           if(!visited[*i]){
             visited[*i] =true;
             queue.push_back(*i);
           }
        }
    }
   }
private:
  int verticeCount;
  //Adjaceny list
  list<int> *adj;
};

int main(){
  Graph g(5);
  g.addEdge(0,1);
  g.addEdge(0,2);
  g.addEdge(1,3);
  g.addEdge(1,4);
     cout << "Following is Breadth First Traversal "
          << "(starting from vertex 2) \n";
     g.BFS(0);
     return 0;
}
