#include<iostream>
#include<vector>
#include<list>
#include<queue>
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
    bool isBipartite(){
        queue<int> q;
        vector<bool> vis(V,-1);
        q.push(0);
        vis[0] = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            list<int> neighbour = l[u];
            for(int val : neighbour){
                if(vis[val] == -1){
                    q.push(val);
                    vis[val] = !vis[u];
                }else{
                    if(vis[val] == vis[u]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
int main(){
    Graph graph(7);
    Graph g(4);
    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,3);
    graph.addEdge(2,4);
    graph.addEdge(3,4);
    graph.addEdge(3,5);
    graph.addEdge(5,6);
    //graph.print();
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,0);
    cout<<graph.isBipartite();
    return 0;
}
