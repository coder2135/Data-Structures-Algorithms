#include<iostream>
#include<vector>
using namespace std;
int coinChange(vector<int> coins, int n, int amount){
    vector<vector<int>> dp(n+1,vector<int>(amount+1));
    for(int i=0;i<=amount;i++){
        dp[0][i] = 0;
    }
    for(int i=0;i<=n;i++){
        dp[i][0] = 1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=amount;j++){
           if(coins[i-1]<=j){
             //dp[i][j] = include + exclude
             dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][amount];
}
int main(){
    vector<int> coins = {1,2,5};
    int amount = 5;
    int n = sizeof(coins)/sizeof(coins[0]);
    cout<<coinChange(coins,n,amount);
    return 0; 
}