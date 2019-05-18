#include <iostream>

using namespace std;

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void rotate(int arr[], int d, int n){
    int temp[d];
    // rotate by d = 2
    // make a temp array of d elements
    // int arr[] = {1,2,3,4,5,6,7};
    // int temp[] = {1,2}
    for(int i = 0; i < d; i++) {
        temp[i] = arr[i];
    }
    // shift the remaining array
    for(int i = 0; i < n-d; i++){
        arr[i] = arr[i+d];
    }
    // resulting array = {3, 4, 5, 6, 7, 6, 7}
    // replace the temp array at the end d elements
    for(int i = 0; i < d; i++){
       arr[n-(d-i)] = temp[i];
    }
    printArray(arr, n);
}

int main() {
    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int d = 2;
    printArray(arr, n);
    rotate(arr, d, n);;
}

// Time Complexity: O(n)
// Space Complexity: O(d)