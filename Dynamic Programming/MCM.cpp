#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int MCMrec(vector<int> dim, int i, int j){
    if(i==j){
        return 0;
    }
    int mini = INT_MAX;
    for(int k=i;k<j;k++){
        int ans = MCMrec(dim,i,k) + MCMrec(dim,k+1,j) + dim[i-1] * dim[j] * dim[k];
        mini = min(ans,mini);
    }
    return mini;
}
int MCMmemo(vector<int> dim, int i , int j, vector<vector<int>> &dp){
    if(i == j){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int mini = INT_MAX;
    for(int k = i; k < j; k++){
        int ans = MCMmemo(dim, i, k, dp) + MCMmemo(dim, k+1, j, dp) + dim[i-1] * dim[k] * dim[j];
        mini = min(ans, mini);
    }
    return dp[i][j] = mini;
}
int MCMtab(vector<int> dim) {
    int n = dim.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int len = 2; len < n; len++) { // chain length
        for (int i = 1; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + dim[i-1] * dim[k] * dim[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[1][n-1];
}
int main(){
    vector<int> dim = {1,2,3,4,3}; //Dimentions of the martices
    int n = dim.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    int ans1 = MCMrec(dim,1,n-1);
    cout<<ans1<<endl;
    int ans2 = MCMmemo(dim,1,n-1,dp);
    cout<<ans2<<endl;
    int ans3 = MCMtab(dim);
    cout<<ans3<<endl;
    return 0;
}