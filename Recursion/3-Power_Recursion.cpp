#include<iostream>
using namespace std;
int power(int x , int n);
int main(){
    int x,n;
    cout<<"Enter number x and power n : ";
    cin>>x>>n;
    int result = power(x,n);
    cout<<"result is : "<<result ;
    return 0;
}
int power(int x,int n){
    //base case
    if(n==0){
        return 1;
    }
    int halfpower = power(x,n/2);     
    int result = halfpower * halfpower;
    if(n%2 != 0){
        result = x * (halfpower * halfpower);
    }

    return result;
}