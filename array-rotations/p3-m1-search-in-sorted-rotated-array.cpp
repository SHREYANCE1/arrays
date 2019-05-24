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
/*Input arr[] = {3, 4, 5, 1, 2}
Element to Search = 1
  1) Find out pivot point and divide the array in two
      sub-arrays. (pivot = 2) Index of 5
  2) Now call binary search for one of the two sub-arrays.
      (a) If element is greater than 0th element then
             search in left array
      (b) Else Search in right array
          (1 will go in else as 1 < 0th element(3))
  3) If element is found in selected sub-array then return index
     Else return -1.*/

int binarySearch(int arr[], int low, int high, int key){
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (arr[mid] == key) {
        return mid;
    }
    if (arr[mid] < key) {
        // search right
        return binarySearch(arr, mid+1, high, key);
    }
    // search left
    return binarySearch(arr, low, mid-1, key);
}

int getPivot(int arr[], int low, int high){
    if (high < low) return -1;
    if (low == high) return low;
    int mid = (low + high) / 2; /*low + (high-low)/2;*/
    if (mid < high && arr[mid] > arr[mid + 1]) {
        return mid;
    }
    if (mid > low && arr[mid] < arr[mid - 1]) {
        return mid - 1; 
    }
    if (arr[low] >= arr[mid]){
        // search left
        return getPivot(arr, low, mid-1);
    }
    return getPivot(arr, mid+1, high);
}

int pivotedBinarySearch(int arr[], int n, int key){
    int pivot = getPivot(arr, 0, n-1);
    // if we did not find the pivot array is not rotated
    // call binary search to the key
    if (pivot == -1){
        return binarySearch(arr, 0, n-1, key);
    }
    // if we found the pivot we first compare with the pivot
    // and then search into two sub-arrays around pivot
    if (arr[pivot] == key) {
        return pivot;
    }
    if (arr[0] <= key) {
        return binarySearch(arr, 0, pivot-1, key);
    }
    return binarySearch(arr, pivot + 1, n-1, key);
}

int main(){
    int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3}, key, index;
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, n);
    cout << "Enter the element to search \n";
    cin >> key;
    index = pivotedBinarySearch(arr, n, key);
    cout << "Element is found at index: " << index << endl;
}

// Time Complexity: O(logn)
// initial solution