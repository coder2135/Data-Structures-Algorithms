#include<iostream>
using namespace std;
int factorial(int n);  //Declaration of function

int main(){
    int n;
    cout<<"Enter number for factorial : ";
    cin>>n;
    int result = factorial(n);   //Calling of the function
    cout<<"Factorial of "<<n<<" is : "<<result<<endl;
    return 0;
}

int factorial(int n){       //Defination of the function
    if(n==0){
        return 1;
    }

    return n * factorial(n-1);
}