#include<iostream>
#include<vector>
using namespace std;
int climbingStairs(int n){   // simple recursion for two option 1 step and 2 steps
    if(n==0 || n==1){
        return n;
    }
    return climbingStairs(n-1) + climbingStairs(n-2);
}
int climbingStairsMemo(int n, vector<int> &f){ //By Memoization O(n)
    if(n == 0 || n == 1){
        return n;
    }
    if(f[n] != -1){
        return f[n];
    }
    f[n] = climbingStairsMemo(n-1 , f) + climbingStairsMemo(n-2 , f);
    return f[n];
}
int climbingStairsTab(int n){   // By Tabulation O(n)
    vector<int> f(n+1,0);
    f[0] = 0;
    f[1] = 1;
    for(int i=2;i<=n;i++){
        f[i] = f[i-1] + f[i-2];
    }
    return f[n];
}
int main(){
    int n = 6;
    vector<int> f(n+1,-1);
    cout<<"climbing stairs by simple recursion : ";
    cout<<climbingStairs(n)<<endl;
    cout<<"climbing stairs by Memoization : ";
    cout<<climbingStairsMemo(n,f)<<endl;
    cout<<"climbing stairs by Tabulation : ";
    cout<<climbingStairsTab(n)<<endl;
    return 0;
}