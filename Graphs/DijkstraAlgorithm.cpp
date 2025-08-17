#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
class Edge{
public: 
   int v;
   int wt;
   Edge(int v, int wt){ 
    this->v = v;
    this->wt = wt;
   }
};
void dijkstra(int src , vector<vector<Edge>> graph , int V){
    vector<int> dist(V,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;//min- heap
    //SAME AS : priority_queue<int , vector<int> , greater<int>> pq
    //pair<int, int> ---> dist[u], src
    pq.push(make_pair(0,src));
    dist[src] = 0;
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        vector<Edge> neighbour = graph[u];
        for(auto e : neighbour){
            if(dist[e.v] > dist[u] + e.wt){  // Edge relaxation
                dist[e.v] = dist[u] + e.wt;
                pq.push(make_pair(dist[e.v],e.v));
            }
        }
    }
    for(auto val : dist){
        cout<<val<<" ";
    }
}
int main(){
    int V = 6;
    vector<vector<Edge>> graph(V);
    graph[0].push_back(Edge(1,2));
    graph[0].push_back(Edge(2,4));
    graph[1].push_back(Edge(2,1));
    graph[1].push_back(Edge(3,7));
    graph[2].push_back(Edge(4,3));
    graph[3].push_back(Edge(5,1));
    graph[4].push_back(Edge(3,2));
    graph[4].push_back(Edge(2,5));
    dijkstra(0,graph,V);
    return 0;
}