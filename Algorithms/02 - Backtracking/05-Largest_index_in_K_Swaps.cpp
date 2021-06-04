// PS : Given a number, find the maximum number you can generate by swapping the digits of the number at most 'k' times
// Explanation : For every index, we store in an array all the indexes of occurrences of the maximum character in the string after that index. If this maximum character is smaller than or equal to the
// character at current index, then there's no point in swapping thus we'll just move to the next index without swapping (i.e. k remains same). In the other case, however, we will one by one swap with each
// of the indexes and choose the maximum one out of them. This is because we cannot be sure as to swapping from which side would give optimal answer.
// Time complexity of this solution is O(n!) and space complexity is O(n)

#include <bits/stdc++.h>
using namespace std;

string largestInK(string s, int idx, int k) {
    if(idx >= s.size() || k == 0) return s;
    char c = s[idx];
    vector<int> indexes = {};
    for(int i=idx+1; i<s.size(); i++) {
        if(s[i] > c) {
            c = s[i];
            indexes = {i};
        }
        else if(s[i] == c) {
            indexes.push_back(i);
        }
    }
    if(indexes.size() == 0 || c <= s[idx])
        return largestInK(s, idx+1, k);
    else {
        // reverse(indexes.begin(), indexes.end());
        string best = s;
        for(int i : indexes) {
            string x = s;
    		char temp = x[idx];
    		x[idx] = x[i];
    		x[i] = temp;
    		best = max(best, largestInK(x, idx+1, k-1));

        }
        return best;
    }
}

string findMaximumNum(string s, int k) {
    return largestInK(s, 0, k);
}

int main() {
    string s = "1258654788";
    int k = 4;
    cout << findMaximumNum(s, k);
}
