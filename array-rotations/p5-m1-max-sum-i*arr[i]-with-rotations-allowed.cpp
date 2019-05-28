#include <iostream>

using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int maxSum(int arr[], int n) {
	// find max of i*arr[i] with only rotations allowed on given array

	// we can do it in O(n^2) by doing all the rotations and comparing the result
 
	// an efficient solution can be to find a relation in prev and current rotation result and finish in one traversal

	// R(i+1) = R(i) + some_relation

	// array -> 1, 3, 5, 7, 9, 11
	// index -> 0  1  2  3  4  5 sum = 0+3+10+21+36+55 = 125

	// nxtRot-> 11, 1, 3, 5, 7, 9	
	// index->  0,  1, 2, 3, 4, 5 sum = 0+1+6+15+28+45 = 95 d= 1 diff = 30

	// nxtRot-> 9, 11, 1, 3, 5, 7
	// index->  0, 1,  2, 3, 4, 5 sum = 0+11+2+9+20+35 = 77 d= 2 diff = 48, 18
	//	sum = 36
	//	R(i+1) = R(i) - (n)(arr[n-i]) + sum
	//		= 95 - (9*6) + 36
	//		= 95 - 54 + 36
	//		= 95 - 18
	// we will not rotate the array and will calculate the rotations with the help of a counter
	// i is the no of rotations
	int arrSum = 0, current_value = 0, max_value;
	for (int i = 0; i < n; i++) {
		arrSum += arr[i];
		current_value += i*arr[i];
	}
	max_value = current_value;
	for (int j = 1; j < n; j++) {
		current_value = current_value - (n)*arr[n-j] + arrSum;
		if (current_value > max_value) {
			max_value = current_value;
		}
	}
	return max_value;
}

int main() {
    int arr[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int n = sizeof(arr)/sizeof(arr[0]);
	int maxSumArr = maxSum(arr, n);
	cout << "The max sum of i * arr[i] with only rotations allowed is " << maxSumArr << endl;
}