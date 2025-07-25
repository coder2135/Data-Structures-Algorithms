#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void slidingWindow(vector<int>vec,int k){
    priority_queue<pair<int,int>> pq;
    for(int i=0;i<k;i++){
        pq.push(make_pair(vec[i],i));
    }
    cout<<"output : "<<pq.top().first<<" ";
    for(int i=k;i<vec.size();i++){
        while(!pq.empty() && pq.top().second <= i-k){
            pq.pop();
        }
        pq.push(make_pair(vec[i],i));
        cout<<pq.top().first<<" ";
    }
}
int main(){
    vector<int> vec = {1,2,3,4,5,6,7,8,9,10};
    int n = vec.size();
    slidingWindow(vec,3);
    return 0;
}