#include <iostream>

using namespace std;

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int gcd(int a, int b) {
    if (a % b == 0){
        return b;
    }
    return gcd(b, a%b);
}

void leftRotate(int arr[], int d, int n){
    int split = gcd(n, d);
    if (split == 1) {

    } else {
        for(int i = 0; i < split; i++){
            // do the iterations and break the loops and 
            // code perfectly according to it
            // any missing conditon or any bad line will not run all the test cases
            // which has been the case with me so far
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    int d = 3;
    leftRotate(arr, d, n);
}