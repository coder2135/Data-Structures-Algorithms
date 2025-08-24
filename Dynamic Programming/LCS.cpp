#include<iostream>
#include<string>
#include<vector>
using namespace std;
//Longest Common Subsequence
int LCSRec(string a,int n, string b, int m){
    if(n == 0 || m == 0){
        return 0;
    }
    if(a[n-1] == b[m-1]){
        return 1 + LCSRec(a,n-1,b,m-1);
    }else{
        return max(LCSRec(a,n-1,b,m),LCSRec(a,n,b,m-1));
    }
}
int LCSMemo(string a,int n ,string b,int m,vector<vector<int>> &dp){
    if(n==0 || m==0){
        return 0;
    }
    if(dp[n][m] != -1){
        return dp[n][m];
    }else{
        if(a[n-1] == b[m-1]){
            dp[n][m] = 1 + LCSMemo(a,n-1,b,m-1,dp);
            return dp[n][m];
        }else{
            dp[n][m] = max(LCSMemo(a,n-1,b,m,dp) , LCSMemo(a,n,b,m-1,dp));
            return dp[n][m];
        }
    }
    return dp[n][m];
}
int LCSTab(string a,int n, string b , int m){
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
int main(){
    string a = "AGGTAB";
    string b = "GXTXAYB";
    int n = a.length();
    int m = b.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    cout<<"LCS by Recursion : ";
    cout<<LCSRec(a,n,b,m)<<endl;
    cout<<"LCS by Memoization : ";
    cout<<LCSMemo(a,n,b,m,dp)<<endl;
    cout<<"LCS by Tabulation : ";
    cout<<LCSTab(a,n,b,m)<<endl;
    return 0;
}