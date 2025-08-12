#include<iostream>
#include<vector>
#include<list>
#include<queue>
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
    void countIndegree(vector<int>&indegree){
        for(int i=0;i<V;i++){
            list<int> neighbour = l[i];
            for(int v : neighbour){
                indegree[v]++;
            }
        }
    }
    void topologicalSort2(){
        vector<int> indegree(V,0);
        countIndegree(indegree);
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            cout<<curr<<" ";
            list<int> neighbour = l[curr];
            for(int v : neighbour){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
    }
};    
int main(){
    Graph g(6,false);
    g.addEdge(5,0);
    g.addEdge(4,0);
    g.addEdge(5,2);
    g.addEdge(2,3);
    g.addEdge(3,1);
    g.addEdge(4,1);
    g.topologicalSort2();
    return 0;
}