// PS : In a given array of integers, we have to find whether there is a 1-3-2 pattern of not, i.e. some integers i,j,k such that i < j < k and arr[k] > arr[i] and arr[k] < arr[j]
// Explanation : First we have to create a min array where we store the minimum value in the array up till that index. Now, we'll take a stack in which we can keep track of elements as
// well as their index, hence stack of pair{int, int}. While adding element from the array to the stack, we pop off all the smaller and equal elements before. Now if the stack is not empty,
// it means that the stack top is greater than the current element, hence 3-2 part achieved. Then we check the minimum element up till the index of the stack top (that's why we kept index in track).
// If this element is smaller than the current element, we've got out 1-3-2 pattern. If no such pattern is found and we've reached the end of the array, then return false

#include <bits/stdc++.h>
using namespace std;

bool recreationalSpot(int arr[], int n){
	int minV[n];
	int mn = arr[0];
	for(int i=0; i<n; i++) {
	    mn = min(mn, arr[i]);
	    minV[i] = mn;
	}
    stack<pair<int, int>> st;
    for(int i=0; i<n; i++) {
        while(!st.empty() && st.top().first <= arr[i])
            st.pop();
        if(!st.empty()) {
            int k = minV[st.top().second];
            if(k < arr[i]) return true;
        }
        st.push({arr[i], i});
    }
    return false;
}

int main() {
    int arr[10] = {2, 4, 8, 1, 1, 1, 2, 2, 2, 2};
    cout << boolalpha << recreationalSpot(arr, 10);
}
