#include <iostream>

using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverseArray(int arr[], int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void rotateClockwiseByN(int arr[], int d, int n) {
    // for normal rotation 
    // AB -> ABr -> ArBr -> (ArBr)r -> BA
    // always look for mirror logic in DS
    // therefore, for clockwise rotation
    // first reverse whole array
    // (AB)r -> BA -> BAr -> BrAr should give the result
    reverseArray(arr, 0, n-1);
    reverseArray(arr, 0, d-1);
    reverseArray(arr, d, n-1);
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int d;
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, n);
    cout << "Enter no of rotations \n";
    cin >> d;
    rotateClockwiseByN(arr, d, n);
    printArray(arr, n);
}