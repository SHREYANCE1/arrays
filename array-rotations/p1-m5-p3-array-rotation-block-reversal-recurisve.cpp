// pending
#include <iostream>

using namespace std;

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void blockSwapArray(int arr[], int fi, int si, int blocksize){
    for(int i = 0; i < blocksize; i++){
        int temp = arr[fi+i];
        arr[fi+i] = arr[si+i];
        arr[si+i] = temp;
    }
}

void leftRotate(int arr[], int d, int n){
    // initialise A=arr[0..d-1] B=arr[d...n-1]
    if (d == 0 || d ==n) return;
    if (d == n-d) {
        blockSwapArray(arr, 0, d, d);
    }
    // length of B is greater than length of A
    // divide B in Bl and Br where lenght of Br is equal to A
    // block swap them    
    if (d < n-d) {
        blockSwapArray(arr, 0, n-d, d);
        leftRotate(arr, d, n-d);
    }
    // length of A is greater than lenght of B
    // divide A in Al and Ar where length of Al is same as B
    // block swap Al and b
    if (d > n-d){
        blockSwapArray(arr, 0, d, n-d);
        printArray(arr, n);
        leftRotate(arr+n-d, 2*d-n, d);
    }
}

int main() {
    int arr[]  = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int d;
    cout << "Enter No of left rotation\n";
    cin >> d;
    d = d % n;
    leftRotate(arr, d, n);
    printArray(arr, n);
}