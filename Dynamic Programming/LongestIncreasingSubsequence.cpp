#include<iostream>
#include<unordered_set>
#include<vector>
#include<algorithm>
using namespace std;
int LCS(vector<int> vec , vector<int> vec2, int n){
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(vec[i-1]==vec2[j-1]){
                dp[i][j] =  1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][n];
}
int LIS(vector<int> vec, int n){
    unordered_set<int> s(vec.begin(),vec.end());//50,3,10,7,40,80
    vector<int> vec2;
    for(int val : s){
        vec2.push_back(val); //50,3,10,7,40,80
    }
    sort(vec2.begin(),vec2.end());//3,7,10,40,50,80
    return LCS(vec,vec2,n);
}
int main(){
    vector<int> vec = {50,3,10,7,40,80};
    int n = vec.size();
    cout<<LIS(vec,n)<<endl;
    return 0;
}