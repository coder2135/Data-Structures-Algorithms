#include<iostream>
#include<vector>
#include<list>
using namespace std;
class Graph{
   int V;
   list<int> *l;
   bool undirect = true;
public:
   Graph(int V,bool undirect){ //To check , graph is directed or undirected
    this->V = V;
    l = new list<int> [V];
    this->undirect = undirect;
   }
   void addEdge(int u , int v){
    l[u].push_back(v);
    if(undirect == true){     //IF Undirected 
        l[v].push_back(u);
    }
   }
   bool cycleHelper(int u,vector<bool>&vis,vector<bool> &path){
    vis[u] = true;
    path[u] = true;
    list<int> neighbour = l[u];
    for(int val : neighbour){
        if(!vis[val]){
            vis[val] = true;
            path[val] = true;
            if(cycleHelper(val,vis,path)){
                return true;
            }
        }else{
            if(path[val]){     //Cycle exist
                return true;
            }
        }
    }
    path[u] = false;
    return false;
   }
   bool isCyclicDir(){
    vector<bool> vis(V,false);
    vector<bool> path(V,false);
    for(int i=0;i<V;i++){
        if(cycleHelper(i,vis,path)){
            return true;
        }
    }
    return false;
   }
};
int main(){
    Graph graph(4,false);
    Graph g(3,false);
    graph.addEdge(1,0);
    graph.addEdge(0,2);
    graph.addEdge(2,3);
    graph.addEdge(3,0);
    //cout<<graph.isCyclicDir();
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,1);
    cout<<g.isCyclicDir();
    return 0;
}