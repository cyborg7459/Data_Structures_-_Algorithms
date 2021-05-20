// PS : Given number 'n', we have to calculate how many different binary search trees we can create using the numbers 1 to n
// For example, for n = 3 there are 5 possible Binary Search trees
//          3     1         2        2       3
//         /       \       / \      /       /
//        2         2     1   3    1       1
//       /           \              \       \
//      1             3              3       2

// Explanation : We can solve this problem by using dynamic programming. The paramenters for the recursive function would be left and right, where [left, right] is the range of elements that
// we're currently dealing with. Now, we can take any element in the range as the root, and then create left and right subtrees from that root. For each such root, suppose that we get 'x' unique left subtrees
// and 'y' unique right subtrees, then for that root and the given range, x*y unique BSTs are possible. Hence we'll calculate the same for each root, and then add up all the values. This would give us the
// total number of unique Binary Search trees in that range. The left subtrees can be found by shrinking the range to [left, root-1] and the right subrtrees can be found by the range [root+1, right].
// Base case is that when left becomes greater than or equal to right

#include <bits/stdc++.h>
using namespace std;

int numOfUniqueBST(int left, int right, map<pair<int, int>, int> &dp) {
    if(left >= right) return 1;
    if(dp.find({left, right}) != dp.end()) return dp[{left, right}];
    int res = 0;
    for(int root = left; root <= right; root++) {
        res += numOfUniqueBST(left, root-1, dp) * numOfUniqueBST(root+1, right, dp);
    }
    dp[{left, right}] = res;
    return res;
}

int numTrees(int n) {
    int ans = 0;
    map<pair<int, int>, int> dp;
    return numOfUniqueBST(1, n, dp);
}

int main() {
	int n = 19;
	cout << numTrees(n);
}
