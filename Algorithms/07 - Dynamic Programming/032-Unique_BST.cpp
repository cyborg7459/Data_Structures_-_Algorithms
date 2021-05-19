// PS : Given number 'n', we have to calculate how many different binary search trees we can create using the numbers 1 to n
// For example, for n = 3 there are 5 possible Binary Search trees
//          3     1         2        2       3
//         /       \       / \      /       /
//        2         2     1   3    1       1
//       /           \              \       \
//      1             3              3       2

// Explanation : We can solve this problem by using dynamic programming. The paramenters for the recursive function would be root, left and right, where root is the element we select as root
// and [left, right] is the range of elements that we're currently dealing with. For each root, we'll get some possilble combinations in the left and some in the right, and mulitplying them would
// give the total number of possible unique combinations with that root in that range. Now, in the initial step, we'll take all elements as the root of the entire tree one by one and add the result.
// Now for each root, we'll have one left subtree and one right subtree. The left subtree will only have numbers smaller than the current root and the right subtree will only have the numbers greater
// than the current root. Hence, the range of elements for the left subtree would be [left, root-1] and for the right subtree would be [root+1, right]. Now we'll repeat the steps for both the subtrees,
// i.e. one by one make all elements the root of that subtree and then again create new subtrees. This can be done using recursion. We keep adding the possible combinations for the left subtree upon taking
// different roots, and the number of combinations for the right subtree upon taking different roots. Finally we mulitply the 2 to get the total number of combinations
// Now the base cases are as follows :-
// 1) If the root becomes equal to the leftmost element of range, it means that there would be no elements to insert in the left subtree for that root. Hence l = 1
// 2) Similarly, if the root becomes equal to the rightmost element of range, it means that there would be no elements for the right subtree, and hence r = 1

#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
int numOfUniqueBST(int root, int left, int right, map<pair<int, pair<int, int>>, int> &dp) {
	cnt++;
	if(dp.find({root, {left, right}}) != dp.end()) return dp[{root, {left, right}}];
	int l = 0, r = 0;
	if(root == left)
		l = 1;
	else {
		for(int i = left; i < root; i++)
			l += numOfUniqueBST(i, left, root-1, dp);
	}
	if(root == right)
		r = 1;
	else {
		for(int i = root+1; i <= right; i++)
			r += numOfUniqueBST(i, root+1, right, dp);
	}
	int res = l*r;
	dp[{root, {left, right}}] = res;
	return res;
}

int numTrees(int n) {
	int ans = 0;
	map<pair<int, pair<int, int>>, int> dp;
	for(int i=1; i<=n; i++) {
		ans += numOfUniqueBST(i, 1, n, dp);
	}
	return ans;
}

int main() {
	int n = 19;
	cout << numTrees(n) << endl;
	cout << cnt << " iterations\n";
}
