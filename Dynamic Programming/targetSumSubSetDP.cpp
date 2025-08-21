#include<iostream>
#include<vector>
using namespace std;
bool targetSum(vector<int> vec , int sum , int n){
    if(sum == 0){
        return true;
    }
    if(n==0){
        return false;
    }
    return targetSum(vec, sum-vec[n-1],n-1) || targetSum(vec,sum,n-1); 
}
bool targetMemo(vector<int> vec,int sum,int n,vector<vector<int>> &t){
    if(sum==0){
        return true;
    }
    if(n==0 || sum <0){
        return false;
    }
    if(t[n][sum] != -1){
        return t[n][sum];
    }else{
        t[n][sum] = targetMemo(vec,sum-vec[n-1],n-1,t) || targetMemo(vec,sum,n-1,t);
    }
    return t[n][sum];
}

bool targetSumTab(vector<int> vec,int sum,int n){
    vector<vector<bool>> t(n+1,vector<bool>(sum+1,false));
    for(int i=0;i<n+1;i++){
        t[i][0] = true;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(vec[i-1] <=j){
                t[i][j] =  t[i-1][j-vec[i-1]] || t[i-1][j];
            }else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][sum];
}
int main(){
    vector<int> nums = {4,2,7,1,3};
    int n = nums.size();
    int target_sum = 17;
    vector<vector<int>> t(n+1,vector<int>(target_sum+1,-1));
    cout<<"Target sum by recursion : ";
    cout<<targetSum(nums,target_sum,n)<<endl;
    cout<<"Target sum by Memoisation : ";
    cout<<targetMemo(nums,target_sum,n,t)<<endl;
    cout<<"Target sum by Tabulation : ";
    cout<<targetSumTab(nums,target_sum,n)<<endl;
    return 0;
}