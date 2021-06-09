// Explanation : The basic solution of this problem is O(n^2). However, with some simple optimisations, we can convert it into O(n*logn) time complexity. Here, only keep track of all the potential
// candidates for adding the next element at. A potential candidate is defined as follows - A potential candidate is the last element of the 'k' length increasing subsequence. If there are 2
// distinct increasing subsequence of k length, we'll always choose the one with the smallest last number. This is because doing so gives us more options to add later on, i.e. if there is a 5-sized
// subsequence ending with 7, and another with 12. Then choosing the first one would be beneficial as it would accomodate any element between 7 and 12 to form a 6-size subsequence, while the latter
// can't do so. Storing the potential candidates in this manner automatically ensures that the array of potential candidates is sorted, both in terms of the last element, as well as the length. Hence
// searching in the array is of log(n) complexity.
// As a base case, we add the first element and length 1 in the respective vectors. Then for all subsequent elements, we find the largest number smaller than that number using lower_bound function. If
// such a number exists, then we can form a new subsequence with size increased by 1. If not, then a single element subsequence is formed. Now, if some subsequence already exists with the given length,
// we'll just compare the last elements and pick whichever one's smaller. This, again, takes O(log(n)) time.

include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i=0; i<n; i++) cin >> v[i];
	vector<int> cand;
	vector<int> len;
	cand.push_back(v[0]);
	len.push_back(1);
	for(int i=1; i<n; i++) {
		int num = v[i];
		auto it = lower_bound(cand.begin(), cand.end(), num);
		int new_cand, new_len;
		if(it == cand.begin()) {
			new_cand = num;
			new_len = 1;
		}
		else {
			it--;
			int idx = it - cand.begin();
			new_cand = num;
			new_len = len[idx] + 1;
		}
		auto it1 = find(len.begin(), len.end(), new_len);
		if(it1 == len.end()) {
			len.push_back(new_len);
			cand.push_back(new_cand);
		}
		else {
			int idx = it1 - len.begin();
			cand[idx] = min(cand[idx], new_cand);
		}
	}
	cout << len[len.size() - 1] << endl;
}
