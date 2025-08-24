#include<iostream>
#include<string>
#include<vector>
using namespace std;
int ED(string s1, string s2){
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    dp[0][0] = 0;
    for(int i=1;i<=n;i++){
        dp[i][0] = i;
    }
    for(int j=1;j<=m;j++){
        dp[0][j] = j;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1] == s2[j-1]){ //if last char of both strings matches
                dp[i][j] = 0 + dp[i-1][j-1];
            }else{  // if not 
                dp[i][j] = 1 + min(dp[i][j-1],min(dp[i-1][j], dp[i-1][j-1])); // min(insert, delete, replace)
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n][m];
}
int main(){
    string s1 = "abc";
    string s2 = "ac";
    string s3 = "horse";
    string s4 = "ros";
    cout<<ED(s1,s2)<<endl;
    cout<<ED(s3,s4)<<endl;
    return 0;
}