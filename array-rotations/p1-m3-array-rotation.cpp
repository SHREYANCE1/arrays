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
// jUGGLINg ALGORITHM
void leftRotate(int arr[], int d, int n){
    int i;
    int g_c_d = gcd(n, d);
    if (g_c_d == 1) {
        // not efficient for gcd = 1
    } else {
        for(int i = 0; i < g_c_d; i++){
            int temp = arr[i];
            int j = i;
            while(1) {
                int k = j + g_c_d;
                if (k >= n) {
                    k = k - n;
                }
                if (k == i) {
                    break;
                }
                arr[j] = arr[k];
                j = k;
            }
            arr[j]  = temp;
        }
    }
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    int d = 2;
    leftRotate(arr, d, n);
    printArray(arr, n);
}