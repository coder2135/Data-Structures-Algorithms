#include<iostream>
#include<vector>
using namespace std;
int fiboMamo(int n,vector<int> &f){
    if(n==0 || n==1){
        return n;
    }
    if(f[n] != -1){  //already calculated , return result
        return f[n];
    }
    f[n] = fiboMamo(n-1,f) + fiboMamo(n-2,f);  //store the result
    return f[n];
}
int main(){
    int n = 6;
    vector<int> f(n+1,-1);
    cout<<fiboMamo(n,f);
    return 0;
}