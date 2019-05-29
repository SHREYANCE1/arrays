#include <iostream>

using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int getPivot (int arr[], int low, int high) {
    if (low > high) {
        return -1;
    }
    if (low == high) {
        return low;
    }
    int mid = (low + high) / 2;
    if (low < mid && arr[mid - 1] > arr[mid]) {
        return mid - 1;
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
    int arr[] = {5, 7, 9, 11, 12};
    int n = sizeof(arr)/sizeof(arr[0]);
    bool clockwise;
    cout << "Is order of rotation clockwise? 1 or 0\n";
    cin >> clockwise;
    printArray(arr, n);
    /*
    * Pivot gives us the max no of sorted rotated array
    * Element next to greatest element (pivot) is min element in sorted and rotated array
    * So if array is rotated clockwise
    * Rotation count will be based on min element
    * And if array is rotated anti-clockwise
    * Rotation count will be based on max element
    * Count direction can be observed based on test cases given in ques
    */
    int rotationCount = getPivot(arr, 0, n-1);
    cout << "rc: " << rotationCount << endl; 
    if (clockwise) {
        // we can notice that the number of rotations is equal to index of minimum element. 
        rotationCount = rotationCount + 1;
    } else {
            // we can notice that the number of rotations is equal to n -index of minimum element. 
        if (rotationCount == -1) {
            rotationCount = 0;
        } else {
            rotationCount = n-(rotationCount + 1);
        }
    }
    cout << "Rotation Count: " << rotationCount << endl;
}
// Time Compelxity: O(n)