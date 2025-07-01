#include<iostream>
#include<string>
using namespace std;
int main(){
    string str = "Hello";
    cout<<str<<endl;
    str = "Aayush Kamboj";
    str = "Hello" + 1;
    cout<<str<<endl; //element after index 1 ello
    string arr;
    cin>>arr;      //don't print whole line
    cout<<arr<<endl;
    string st;
    getline(cin,st,'.');
    cout<<st;
    return 0;
}