#include<iostream>
using namespace std;
int binarysearch(int *arr,int n,int target);
int main(){
    int arr[] = {1,2,3,4,5,6,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target ;
    cout<<"Enter target element : ";
    cin>>target;
    int result = binarysearch(arr,n,target);
    if(result == 1){
        cout<<"Element is at index : "<<result;
    }
}
int binarysearch(int *arr,int n,int target){
    int left = 0;
    int right = n-1;
    while(arr[left]<=arr[right]){
        int mid = (left + right)/2;
        if(target == arr[mid]){
            return mid;
        }else if(target < arr[mid]){ //left side
            right = mid - 1;
        }else{                       //Right side
            left = mid + 1;
        }
    }
    cout<<"Element not found , enter another element ";
    return 0;
}