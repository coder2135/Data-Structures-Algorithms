#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool wildcardMatching(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();
    vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

    // Empty string matches empty pattern
    dp[0][0] = true;

    // If string is empty, pattern must be all '*'
    for (int j = 1; j <= m; j++) {
        if (s2[j-1] == '*')
            dp[0][j] = dp[0][j-1];
    }

    // Fill the dp table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s2[j-1] == s1[i-1] || s2[j-1] == '?') {
                dp[i][j] = dp[i-1][j-1];
            } else if (s2[j-1] == '*') {
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            } else {
                dp[i][j] = false;
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return dp[n][m];
}

int main() {
    string s1 = "baaabab";
    string s2 = "**ba****ab";
    string s3 = "abcd";
    string s4 = "*b*?";

    cout << wildcardMatching(s1, s2) << endl; // should print 1 (true)
    cout << wildcardMatching(s3, s4) << endl; // should print 0 (false)

    return 0;
}
