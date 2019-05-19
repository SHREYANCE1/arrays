#include <iostream>

using namespace std;

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void reverseArray(int arr[], int start, int end){
    while (start < end){
        int temp = arr[start];
        arr[start]  = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

// Let AB are the two parts of the input array where 
// A = arr[0..d-1] and B = arr[d..n-1]. The idea of the algorithm is :
// Reverse A to get ArB, where Ar is reverse of A.
// Reverse B to get ArBr, where Br is reverse of B.
// Reverse all to get (ArBr) r = BA.

void leftRotate(int arr[], int d, int n){
    reverseArray(arr, 0, d-1);
    reverseArray(arr, d, n-1);
    reverseArray(arr, 0, n-1);
}

/* Driver program to test above functions */
int main() 
{ 
    int arr[] = {1, 2, 3, 4, 5, 6, 7}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int d = 2; 
  
    // in case the rotating factor is  
    // greater than array length 
    d = d % n;   
      
    printArray(arr, n);
    // Function calling
    leftRotate(arr, d, n); 
    printArray(arr, n); 
      
    return 0; 
} 