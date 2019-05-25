// Program to search an element in sorted and rotated array
/*An element in a sorted array can be found in O(log n) time via binary search
But suppose we rotate an ascending array at some pivot unknown beforehand.
So for instance 1 2 3 4 5 might become 3 4 5 1 2. Devise a way to find an
element in the rotated array in O(log n) time
Input  : arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
         key = 3
Output : Found at index 8

Input  : arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
         key = 30
Output : Not found*/
// Assumptions all the elements in the array are distinct
#include <iostream>

using namespace std;

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int search(int arr[], int low, int high, int key) {
    if (low > high) {
        return -1;
    }
    int mid = (low + high) / 2;
    if (arr[mid] == key) {
        return mid;
    }
    // rotated array
    // 1 3 5 7 9 
    // 3 5 7 9 1
    // 5 7 9 1 3
    // 7 9 1 3 5
    // 9 1 3 5 7
    // 5, 6, 7, 8, 9, 10, 1, 2, 3
    if (arr[mid] >= arr[low]) {
        // left is sorted
        if (key >= arr[low] && arr[mid] >= key) {
            return search(arr, low, mid-1, key);
        }
            return search(arr, mid+1, high, key);
    } else {
        // right of mid is sorted
        if (key >= arr[mid] && key <= arr[high]){
            return search(arr, mid + 1, high , key);
        }
            return search(arr, low, mid-1, key);
    }
}

int main(){
    int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3}, key, index;
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, n);
    cout << "Enter the element to search \n";
    cin >> key;
    index = search(arr, 0, n-1, key);
    cout << "Element is found at index: " << index << endl;
}
