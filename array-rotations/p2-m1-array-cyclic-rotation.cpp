// program to cyclically rotate an array by one
// Input: arr[] = {1, 2, 3, 4, 5} 
// Output: arr[] = {5, 1, 2, 3, 4}
#include <iostream>

using namespace std;

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void rotateCyclically(int arr[], int n){
    int temp = arr[n-1], i;
    for(i = n-1; i > 0; i--){
        arr[i] = arr[i-1];
    }
    arr[i] = temp;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, n);
    rotateCyclically(arr, n);
    printArray(arr, n);
}

// Time Complexity : O(n)
// Space Complexity: O(1)