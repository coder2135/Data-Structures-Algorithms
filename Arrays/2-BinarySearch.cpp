#include <iostream>
using namespace std;

//performs binary search
int binary_search(int *arr, int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {  
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        } 
        else if (target < arr[mid]) {
            right = mid - 1;
        } 
        else {
            left = mid + 1;
        }
    }

    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    int target;
    cout << "Enter target element: ";
    cin >> target;

    int index = binary_search(arr, n, target);

    if (index != -1) {
        cout << "Element found at index: " << index << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
