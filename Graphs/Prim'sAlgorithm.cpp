#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

class Graph {
    int V;
    bool isUndirected;
    list<pair<int, int>> *l;

public:
    Graph(int V, bool isUndirected) {
        this->V = V;
        this->isUndirected = isUndirected;
        l = new list<pair<int, int>>[V];
    }

    void addEdge(int u, int v, int wt) {
        l[u].push_back({v, wt});
        if (isUndirected) {
            l[v].push_back({u, wt});
        }
    }

    void primAlgorithm(int src) {
        vector<bool> mst(V, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // {wt, vertex} -> min-heap
        pq.push({0, src});
        int ans = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            int wt = pq.top().first;
            pq.pop();

            if (!mst[u]) {
                mst[u] = true;
                ans += wt;

                for (auto val : l[u]) {
                    int neighbour = val.first;
                    int edgeWt = val.second;
                    if (!mst[neighbour]) {
                        pq.push({edgeWt, neighbour});
                    }
                }
            }
        }
        cout << "Total MST weight is: " << ans << endl;
    }
};

int main() {
    Graph graph(4, true);
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 15);
    graph.addEdge(0, 3, 30);
    graph.addEdge(1, 3, 40);
    graph.addEdge(2, 3, 50);
    graph.primAlgorithm(0);
    return 0;
}
