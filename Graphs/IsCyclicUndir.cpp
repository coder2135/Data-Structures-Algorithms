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
    void DFS(int u, vector<bool>& vec){
        vec[u] = true;
        cout<<u<<" ";
        list<int> neightbour = l[u];
        for(int val : neightbour){
            if(!vec[val]){
                DFS(val,vec);
            }
        }
    }
    bool cyclicHelper(int u,int src,vector<bool>&vis){
        vis[u] = true;
        list<int> neighbour = l[u];
        for(int val : neighbour){
            if(!vis[val]){
                if(cyclicHelper(val,u,vis)){
                    return true;
                }
            }else{
                if(val!=src){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCyclicUndir(){
        vector<bool> vis(V,false);
        return cyclicHelper(0,-1,vis);
    }
};
int main(){
    Graph graph(5);
    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(0,3);
    graph.addEdge(1,2);
    graph.addEdge(3,4);
    cout<<graph.isCyclicUndir();
    return 0;
}
