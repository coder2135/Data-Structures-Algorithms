#include<iostream>
#include<string.h>
using namespace std;
void ReverseStr(char arr[] , int n);
int main(){
    char arr[] = "AAYUSH";
    int n = strlen(arr);
    ReverseStr(arr,n);
    return 0;
}
void ReverseStr(char arr[] , int n ){
    for(int i=0;i<n/2;i++){
        int temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    }
    cout<<arr<<endl;
}