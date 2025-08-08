#include<iostream>
#include<vector>
#include<list>
using namespace std;
class Graph{
    int V;
    list<int> *l; 
public:
    Graph(int V){
        this-> V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    
    void print(){
        for(int u=0;u<V;u++){
            list<int> neighbour = l[u];
            cout<<u<<" : ";
            for(int v: neighbour){
                cout<<v<<" ";
            }
            cout<<endl;
        }
    }
    void helper(int u, vector<bool>& vis){
        vis[u] = true;
        cout<<u<<" ";
        list<int> neightbour = l[u];
        for(int val : neightbour){
            if(!vis[val]){
                helper(val,vis);
            }
        }
    }
    void DFS(){                    //DFS for DISCONNECTED graph
        vector<bool> vis(V,false);
        for(int i=0;i<V;i++){     //CHECK for unvisited vertices (DISCONNECTED)
            if(!vis[i]){
                cout<<endl;
                helper(i,vis);
            }
        }
    }
};
int main(){
    Graph graph(10);
    graph.addEdge(1,6);
    graph.addEdge(6,4);
    graph.addEdge(4,9);
    graph.addEdge(4,3);
    graph.addEdge(3,8);
    graph.addEdge(3,7);
    graph.addEdge(0,2);
    graph.addEdge(2,5);
    //graph.print();
    graph.DFS();
    return 0;
}
