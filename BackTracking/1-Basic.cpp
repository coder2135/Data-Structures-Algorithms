#include<iostream>
using namespace std;
void print(int arr[],int n ){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void changeArr(int arr[],int n, int i){
    if(i==n){
        print(arr,n);
        return ;
    }
    arr[i] = i+1;  //Some operations 
    changeArr(arr,n,i+1);  //Recursion
    arr[i] -= 2;  //BackTracking (Always comes after recursion call)
}
int main(){
    int arr[5] = {0};
    int n = 5;
    print(arr,n);
    changeArr(arr,n,0);
    print(arr,n);
    return 0;
}