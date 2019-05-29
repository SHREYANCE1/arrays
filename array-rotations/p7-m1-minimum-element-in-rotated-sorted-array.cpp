#include <iostream>

using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int getPivot(int arr[], int low, int high) {

    if (low > high) return -1;
    if (low == high) return 0;
    int mid = (low + high) / 2;
    if (low < mid && arr[mid-1] > arr[mid]) {
        return mid-1;
    }
    if (mid < high && arr[mid] > arr[mid+1]) {
        return mid;
    }
    if (arr[low] >= arr[mid]) {
        // search left
        return getPivot(arr, low, mid-1);
    }
    // search right
    return getPivot(arr, mid+1, high);
}

int main() {
    int arr[] = {2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    /*
    * Pivot gives us the index of max no of sorted rotated array
    * Element next to greatest element (pivot) is min element in sorted and rotated array
    */
    int pivot = getPivot(arr, 0, n-1);
    int minElement;
    if (pivot == -1) {
        minElement = arr[0];
    } else {
        minElement = arr[pivot+1];
    }
    cout << "Min Element: " << minElement << endl;
}