#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph {
    int V;
    bool isUndirected = true;
    list<int> *l;
public: 
    Graph(int V, bool isUndirected) {
        this->V = V;
        l = new list<int>[V];
        this->isUndirected = isUndirected;
    }
    void addEdge(int u, int v) {
        l[u].push_back(v);
        if(isUndirected) {
            l[v].push_back(u);
        }
    }
    void pathHelper(int src,int dest,vector<bool> &vis,string&path){
        if(src == dest){   //BASE CASE
            cout<<path<<dest<<endl;
            return ;
        }
        vis[src] = true;
        path += to_string(src);
        list<int> neighbour = l[src];
        for(int val : neighbour ){
            if(!vis[val]){
                pathHelper(val,dest,vis,path);
            }
        }
        path = path.substr(0,path.size()-1);  //BACKTRACKING
        vis[src] = false;
    }
    void allPath(int src, int dest){
        vector<bool> vis(V,false);
        string path = "";
        pathHelper(src,dest,vis,path);
    }
};

int main() {
    Graph g(6, false);
    g.addEdge(5,0);
    g.addEdge(5,2);
    g.addEdge(0,3);
    g.addEdge(3,1);
    g.addEdge(0,4);
    g.addEdge(4,1);
    g.allPath(5,1);
    return 0;
}