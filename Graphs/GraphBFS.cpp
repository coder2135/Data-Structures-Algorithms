#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;
//Using Adjacent list -> Vertices : And its edges(neighbour) -> list<int>[v]
class Graph{
    int V;
    list<int> *l;  //Dynamically - > datatype *arr; -> arr = new datatype[5];
public:
    Graph(int V){
        this-> V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v){ //For undirected graph
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
    
    void BFS(){  //O(V + E)
        vector<bool>vec(V,false);
        queue<int> q;
        q.push(0);
        vec[0] = true;
        while(q.size()>0){
            int u = q.front();
            q.pop();
            cout<<u<<" ";
            list<int> neighbour = l[u];
            for(int val : neighbour){
                if(!vec[val]){
                    vec[val] = true;
                    q.push(val);
                }
            }
        }
        cout<<endl;
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
    graph.addEdge(5,6);
    graph.print();
    graph.BFS();
    return 0;
}
