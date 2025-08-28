#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// Recursive method: returns minimum difference between two subsets
int minPartitionRec(vector<int>& nums, int n, int sumCalculated, int totalSum) {
    if (n == 0)
        return abs((totalSum - sumCalculated) - sumCalculated);
    return min(
        minPartitionRec(nums, n - 1, sumCalculated + nums[n - 1], totalSum),
        minPartitionRec(nums, n - 1, sumCalculated, totalSum)
    );
}

// Tabulation method
int minPartitionTab(vector<int>& nums) {
    int n = nums.size();
    int totalSum = 0;
    for (int num : nums) totalSum += num;

    vector<vector<bool>> dp(n + 1, vector<bool>(totalSum + 1, false));
    for (int i = 0; i <= n; i++) dp[i][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= totalSum; j++) {
            dp[i][j] = dp[i - 1][j];
            if (nums[i - 1] <= j)
                dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
        }
    }

    int minDiff = INT_MAX;
    for (int s1 = 0; s1 <= totalSum / 2; s1++) {
        if (dp[n][s1]) {
            int s2 = totalSum - s1;
            minDiff = min(minDiff, abs(s2 - s1));
        }
    }
    return minDiff;
}

int main() {
    vector<int> nums = {1, 6, 11, 5};
    int n = nums.size();
    int totalSum = 0;
    for (int num : nums) totalSum += num;

    cout << "Minimum partition difference (Recursion): "
         << minPartitionRec(nums, n, 0, totalSum) << endl;

    cout << "Minimum partition difference (Tabulation): "
         << minPartitionTab(nums) << endl;

    return 0;
}