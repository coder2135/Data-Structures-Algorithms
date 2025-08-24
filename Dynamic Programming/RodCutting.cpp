#include<iostream>
#include<vector>
using namespace std;
int maxProfit(vector<int> prices,vector<int> length, int rodlength , int n){
    vector<vector<int>> dp(n+1,vector<int>(rodlength+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=rodlength;j++){
            if(length[i-1] <= j){
                dp[i][j] = max(prices[i-1] + dp[i][j-length[i-1]],dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][rodlength];
}
int main(){
    vector<int> prices = {1,5,8,9,10,17,17,20};
    vector<int> length = {1,2,3,4,5,6,7,8};
    int rodlength = 8;
    int n = length.size();
    cout<<maxProfit(prices,length,rodlength,n);
    return 0;
}