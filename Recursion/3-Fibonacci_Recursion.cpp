#include<iostream>
using namespace std;

int fibo(int n) {
    if(n==0 || n == 1) {
        return n;
    } 
    return fibo(n-1) + fibo(n-2);
}

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;
    cout << "Fibonacci series: ";
    for(int i = 0; i < n; i++) {
        cout << fibo(i) << " ";
    }
    cout << endl;
    return 0;
}