// Problem: https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1#
// Explanation: We can solve this question by using the divide and conquer approach. To find the number of inversions, what we can do is divide the array into 2 parts and add up the number of inversions in both
// parts. Now, some inversions are still left, which can be then taken into account using merge sort procedure. While doing merge sort, if the element from right array is smaller than the current element in the left
// array, then it is also smaller to all the remaining elements of the left array (since the left and right arrays are individually sorted). Hence, we can simply add those many inversions to the final answer, while
// simultaneously sorting the array

#include <bits/stdc++.h>
using namespace std;

long long merge(long long arr[], long long temp[], int left, int mid, int right) {
	long long ans = 0;
	int i=left, j=mid, k=left;
	while(i<mid && j<=right) {
		if(arr[i]<=arr[j]) temp[k++] = arr[i++];
		else {
			ans += (mid-i);
			temp[k++] = arr[j++];
		}
	}
	while(i<mid) temp[k++] = arr[i++];
	while(j<=right) temp[k++] = arr[j++];

	for(int i=left; i<=right; i++) arr[i] = temp[i];
	return ans;
}

long long mergeSort(long long arr[], long long temp[], int left, int right) {
    long long ans = 0;
    if(right > left) {
        int mid = (left + right)/2;
        ans += mergeSort(arr, temp, left, mid);
        ans += mergeSort(arr, temp, mid+1, right);
        ans += merge(arr, temp, left, mid+1, right);
    }
    return ans;
}

long long int inversionCount(long long arr[], long long N) {
  long long temp[N] = {};
  return mergeSort(arr, temp, 0, N-1);
}

int main() {
  long long arr[10] = {4,2,3,7,6,9,4,2,5,6};
  cout << inversionCount(arr, 10);
}
