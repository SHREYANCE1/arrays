#include <iostream>

using namespace std;

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int findPairWithGivenSumSorted(int arr[], int n, int key) {
    // for simplicity lets make array sorted case first
    // 6,7,8,9,10,11,15
	// sum = 16
    // using 2 pointer approach i and j
	int i = 0, j = n-1;
	int cnt = 0;
	while (i != j) {
		int sum = arr[i] + arr[j];
		if (sum == key) {
			cnt++;
			i++;
		} else if (sum < key) {
			i++;
		} else if (sum > key) {
			j--;
		}
	}
	
    	if (cnt == 0) {
		return -1;
	};
	return cnt;
}

int getPivot(int arr[], int low, int high) {
	if (low > high) {
		return -1;
	}
	if (low == high) {
		return low;
	}
	int mid = (low + high) / 2;
	if (low < mid && arr[mid -1] > arr[mid]) {
		return mid - 1;
	}
	if (mid < high && arr[mid] > arr[mid+1]) {
		return mid;
	}
	if (arr[low] >= arr[mid]) {
		// search left
		return getPivot(arr, low, mid-1);
	}
	return getPivot(arr, mid + 1, high);
}

int findPairWithSumRotated(int arr[], int n, int key){
	// this logic is working fine for the sorted array
	// now taking the case of sorted and rotated array
	// 6, 8, 9, 10, 11, 15
	// 8, 9, 10, 11, 15, 6
	// 9, 10, 11, 15, 6, 8
	// 10, 11, 15, 6, 8, 9
	// 11, 15, 6, 8, 9, 10
	// 15, 6, 8, 9, 10, 11
	// key is 23
	// using the pivot you can find if a give sum exits?
	int i , j, cnt = 0;
	int pivot = getPivot(arr, 0, n-1);
	if (pivot == -1) {
		i = 0; // (min. no of array)
		j = n-1; // (max. no of array)
	} else {
		j = pivot; // (max. no of array)
		i = pivot + 1; // (min. no of array)
	}
	while (i != j) { // !important since value of j first decreases and then increases 
                    // only eqality testing can be helpful
		int sum = arr[i] + arr[j];
		if (sum == key) {
			cnt++;
			j = (j - 1 + n) % n;
		} else if (sum < key) {
			i = (i + 1) % n;
		} else if (sum > key) {
			j = (j - 1 + n) % n;
		}
	}
	if (cnt == 0) {
		return -1;
	}
	return cnt;
}

int main() {
    int arr[] = {11, 15, 6, 7, 8, 9};
    int arrSorted[] = {6, 7, 8, 9, 10, 11, 15};
    int sum = 18;
    int sumR = 20;
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, n);
    int cntSorted = findPairWithGivenSumSorted(arrSorted, n, sum);
    cout << "No of pairs in sorted array: " << cntSorted << endl;
    int cntSortedAndRotated = findPairWithSumRotated(arr, n, sumR);
    cout << "No of pairs in sorted and rotated array: " << cntSortedAndRotated << endl;
}

// Time Complexity -
// findPivot in O(log n)
// findPairs in O(n)