#include<iostream>
using namespace std;

void selectionSort(int *arr, int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i+1; j < n ; j++) {
            if(arr[i] > arr[j ]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

int main() {
    int arr[] = {5, 7, 3, 2, 4, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Array before sorting: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    
    selectionSort(arr, n);
    
    cout << "Array after sorting: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
     
    return 0;
}