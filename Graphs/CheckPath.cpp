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
    bool checkPath(int s ,int d ,vector<bool> &vis){
        vis[s] = true;
        if(s==d){
            return true;
        }
        list<int> neighbour = l[s];
        for(int val : neighbour){
            if(!vis[val]){
                if(checkPath(val,d,vis)){
                 return true;
                }
            }
        }
        return false;
    }
};
int main(){
    Graph graph(7);
    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,3);
    graph.addEdge(2,4);
    graph.addEdge(3,4);
    graph.addEdge(3,5);
    graph.addEdge(4,5);
    graph.addEdge(5,6);
    graph.print();
    vector<bool> vis(7,false);
    cout<<"Path : ";
    if(graph.checkPath(0,6,vis)){
        cout<<"exist";
    }else{
        cout<<"not-exist";
    }
    return 0;
}
