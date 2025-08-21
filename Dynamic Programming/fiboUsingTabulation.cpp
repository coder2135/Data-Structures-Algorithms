#include<iostream>
#include<vector>
using namespace std;
int fiboTab(int n){
    vector<int> f(n+1,0);
    f[0] = 0;   // storing basecases
    f[1] = 1;
    for(int i=2;i<=n;i++){    //iteration for strong fibo until n 
        f[i] = f[i-1] + f[i-2];
    }
    return f[n];  // return result 
}
int main(){
    int n = 6;
    cout<<fiboTab(n)<<endl;
    return 0;
}