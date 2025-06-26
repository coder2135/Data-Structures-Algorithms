#include<iostream>
using namespace std;
void ascending(int n); // Declaration 

int main(){
    int n;
    cout<<"Enter number : ";
    cin>>n;
    cout<<"Ascending order is : ";
    ascending(n);  //Calling 
    return 0;
}

void ascending(int n){ // Definition 
    if(n==0){
        return ;
    }
    ascending(n-1); // Recursive call
    cout<<n<<" ";
}