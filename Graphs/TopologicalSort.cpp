#include<iostream>
#include<vector>
#include<list>
#include<stack>
using namespace std;
class Graph{
    int V;
    list<int> *l;
    bool isUndirected = true;
public:
    Graph(int V,bool isUndirected){
        this->V = V;
        l = new list<int>[V];
        this->isUndirected = isUndirected;
    }
    void addEdge(int u,int v){
        l[u].push_back(v);
        if(isUndirected){
            l[v].push_back(u);
        }
    }
    void topoHelper(int u,vector<bool> &vis,stack<int>& s){
        vis[u] = true;
        list<int> neighbour = l[u];
        for(int val : neighbour){
            if(!vis[val]){
                topoHelper(val,vis,s);
            }
        }
        s.push(u);
    }
    void topologicalSort(){
        vector<bool> vis(V,false);
        stack<int>s;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                topoHelper(i,vis,s);
            }
        }
        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop(); 
        }
    }
};
int main(){
    Graph g(6,false);
    g.addEdge(5,0);
    g.addEdge(4,0);
    g.addEdge(4,1);
    g.addEdge(5,2);
    g.addEdge(3,1);
    g.addEdge(2,3);
    g.topologicalSort();
    return 0;
}