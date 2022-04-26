// PS : Given an array, find the number of distinct unordered pairs of (i, j) such that a[i] + a[j] belongs in the range [L, R]
// Explanation : For this problem, we'll need a sorted array. For each element x, the second element should lie in the range of [L-x, R-x]. Now, we'll break if x itself is greater than R because due to sorted array
// we'll find no solutions ahead. Secondly, if (L-x) > largest element in the array, then we can start the next iteration as no element would be possible this time as well. After this, we compress the range if possible,
// i.e. the lower limit should be gte x+1 (for the sake of simplicity, we'll handle multiple occurrences of same element giving the sum in the required range separately, using a map), and the upper limit should be lte max
// v[n-1]. Once this is done, then for the left limit, we'll find the lower bound, and for the right limit, we'll find the upper bound and subtract 1 (because for L-x we need the first occurrence and for R-x we need the
// last occurrence). Hence we got the range of integers and we can add the length of the subarray

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, l, r;
	cin >> n >> l >> r;
	vector<int> v(n);
	map<int, int> mp;
	for(int i = 0; i < n; i++) {
		cin >> v[i];
		if(mp.find(v[i]) == mp.end())
			mp.insert({v[i], 1});
		else
			mp[v[i]]++;
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for(int i = 0; i < n; i++) {
		int num = v[i];
		if(2*num >= l && 2*num <= r) {
			int t = mp[num];
			ans += (t*(t-1))/2;
			mp[num] = 0;
		}
		if(num > r) break;
		int a = l - num;
		int b = r - num;
		if(a > v[n-1]) continue;
		a = max(a, num+1);
		b = min(b, v[n-1]);
		if(b < a) continue;
		int i1 = lower_bound(v.begin(), v.end(), a) - v.begin();
		auto it = upper_bound(v.begin(), v.end(), b);
		it--;
		int i2 = it - v.begin();
		ans += i2 - i1 + 1;
	}
	cout << ans;
}
