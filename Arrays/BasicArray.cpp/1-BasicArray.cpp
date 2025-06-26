#include<iostream>
using namespace std;
int main(){
    char arr[6] = {'a','y','u','s','h','\0'};
    char arr1[30];
    char arr2[30];
    char arr3[] = {"Aayush Kamboj"};
    cout<<arr<<endl;
    /*If you only give size 5 this will print ayush@ @ for 
    not adding null character in the end */
    cin>>arr1;
    cout<<arr1<<endl; //This will only output first word not full line
    cin.getline(arr2,30,'*');
    cout<<arr2<<endl;
    cout<<arr3<<endl;
    return 0;
}
//Same for integer array
// int arr[5] = {1,2,3,4,5};