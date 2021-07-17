// PS : Given the number of pages in 'n' books each, we have to distribute books contiguously to 'm' students in such a way that the maximum number of pages a student is reading is minimized
// Explanation : This problem can be solved using Binary Search. First of all if m > n then straightaway no solution is possilbe. Now, we find the total sum of all pages, and the do binary search
// in such a way that if it is possible to achieve the current mid, then we move the end to mid-1 (since our goal is to keep minimizing for as long as it allows), else we'll move it to mid+1.
// To check possible, we know that we have taken mid to be the maximum number of pages a student has to read. Hence, we'll start from the beginning and distribute books contiguously to students in
// such a way that none of them gets more that mid books (increment student count if it does to indicate that the current book was given to a new student to maintain mid as the maximum). If the value
// of mid we've taken is too small, then we'd need more than 'm' students to satisfy the condition, and hence we can check for this inequality and return T/F accordingly

#include <bits/stdc++.h>
using namespace std;

bool isPossible(int arr[], int n, int m, int cur) {
	int stu = 1, sum = 0;
	for(int i=0; i<n; i++) {
		if(arr[i] > cur) return false;
		if(sum + arr[i] > cur) {
			stu++;
			sum = arr[i];
			if(stu > m) return false;
		} else sum += arr[i];
	}
	return true;
}

int findPages(int arr[], int n, int m) {
	long long sum = 0;
	if(n < m) return -1;
	for(int i=0; i<n; i++)
		sum+=arr[i];
	int start = 0, end = sum, result = 1000000000;
	while(start <= end) {
		int mid = (start+end)/2;
		if(isPossible(arr, n, m, mid)) {
			result = min(result, mid);
			end = mid - 1;
		} else start = mid+1;
	}
	return result;
}

int main() {
	int arr[4] = {12, 34, 67, 90};
	int n = 4;
	int m = 2;
	cout << findPages(arr, n, m);
}
