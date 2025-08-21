#include<iostream>
#include<vector>
using namespace std;

int knapsackRec(vector<int> val, vector<int> wt, int n, int W) {
    if (n == 0 || W == 0) {
        return 0;
    }
    if (wt[n - 1] <= W) {
        int ans1 = knapsackRec(val, wt, n - 1, W - wt[n - 1]) + val[n - 1];
        int ans2 = knapsackRec(val, wt, n - 1, W);
        return max(ans1, ans2);
    } else {
        return knapsackRec(val, wt, n - 1, W);
    }
}

int knapsackMemo(vector<int> val, vector<int> wt, int n, int W, vector<vector<int>>& K) {
    if (n == 0 || W == 0) {
        return 0;
    }
    if (K[n][W] != -1) {
        return K[n][W];
    }
    if (wt[n - 1] <= W) {
        int ans1 = knapsackMemo(val, wt, n - 1, W - wt[n - 1], K) + val[n - 1];
        int ans2 = knapsackMemo(val, wt, n - 1, W, K);
        K[n][W] = max(ans1, ans2);
    } else {
        K[n][W] = knapsackMemo(val, wt, n - 1, W, K);
    }
    return K[n][W];
}

int knapsackTab(vector<int> val,vector<int> wt, int n, int W){
    vector<vector<int>> k(n+1,vector<int>(W+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            if(wt[i-1] <= j){
                k[i][j] = max(k[i-1][j], val[i-1] + k[i-1][j-wt[i-1]]);
            }else{
                k[i][j] = k[i-1][j];
            }
        }
    }
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=W;j++){
    //         cout<<k[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    return k[n][W];
}

int main() {
    int n = 5;
    int W = 7;
    vector<int> val = {15, 14, 10, 45, 30};
    vector<int> wt = {2, 5, 1, 3, 4};
    vector<vector<int>> K(n + 1, vector<int>(W + 1, -1));
    cout << knapsackRec(val, wt, n, W) << endl;
    cout << "By memoization : ";
    cout << knapsackMemo(val, wt, n, W, K) << endl;
    cout << "By Tabulation : ";
    cout << knapsackTab(val, wt, n, W) << endl;
    return 0;
}