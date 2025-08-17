#include<iostream>
#include<vector>
#include<list>
using namespace std;
class DisjointSet{
    int V;
    list<int> *l;
    vector<int> par;
    vector<int> rank;
public: 
    DisjointSet(int V){
        this->V = V;
        l = new list<int> [V];
        for(int i=0;i<V;i++){
            par.push_back(i);
            rank.push_back(0);
        }
    }
    int find(int x){
        if(par[x] == x){
            return x;
        }
        return par[x] = find(par[x]);
    }
    void unionByRank(int a , int b){
        int parA = find(a);
        int parB = find(b);
        if(rank[parA] == rank[parB]){
            par[parB] = parA;
            rank[parA]++;
        }else if(rank[parA] > rank[parB]){
            par[parB] = parA; 
        }else{
            par[parA] = parB;
        }
    }
    void getInfo(){
        for(int i=0;i<V;i++){
            cout<<i<<":"<<par[i]<<":"<<rank[i]<<endl;
        }
    }
};
int main(){
    DisjointSet set(5);
    set.unionByRank(0,2);
    set.unionByRank(1,3);
    set.unionByRank(2,5);
    set.unionByRank(0,3);
    set.unionByRank(0,4);
    set.getInfo();
    return 0;
}