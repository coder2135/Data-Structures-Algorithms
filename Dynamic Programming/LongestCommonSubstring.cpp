#include<iostream>
#include<string>
#include<vector>
using namespace std;
//Longest Common Substring
int LCS(string a, int n, string b, int  m){
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = 0;
            }
            ans = max(ans,dp[i][j]);
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return ans;
}
int main(){
    string a = "abcde";
    string b = "abgce";
    int n = a.length();
    int m = b.length();
    cout<<"longest common substring : \n";
    cout<<LCS(a,n,b,m);
    return 0;
}