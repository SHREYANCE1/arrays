#include <iostream>

using namespace std;

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// rotate array by one
void rotateByOne(int arr[], int n){
    int temp = arr[0], i;
    for(i = 0; i <  n-1; i++){
        arr[i] = arr[i+1];
    }
    arr[i] = temp;
}

void leftRotate(int arr[], int d, int n){
    for(int i = 0; i < d; i++){
        rotateByOne(arr, n);
    }
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int d = 2;
    printArray(arr, n);
    leftRotate(arr, d, n);
    printArray(arr, n);
}

// Time : O(n*d)
// Space: O(1)