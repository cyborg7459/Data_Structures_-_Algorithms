// Explanation : KMP algorithm can be used to find all the occurrences of a given pattern in a string in O(n) time, a big optimization over the naive O(nm).
// For the given algorithm we need to have a longest prefix suffix (LPS) array, which can be formed in O(n).
// The algorithm explanation : https://www.youtube.com/watch?v=V5-7GzOfADQ&t=697s
// An important point to note is that when the pattern is obtained, we do not go back to index 0 in the pattern, but rather to the previous index from which it is same (using lp array)

#include<bits/stdc++.h>
using namespace std;

vector <int> KMPsearch(string s, string txt) {
    int n = s.length();
    int lps[n+1];
    lps[0] = 0;
    lps[1] = 0;
    int start = 0;
    for(int i=2; i<=n; i++) {
        char c = s[i-1];
        if(c == s[start]) {
            lps[i] = start+1;
            start++;
        }
        else {
            if(start == 0) {
                lps[i] = 0;
                continue;
            }
            else {
                start = lps[start];
                i--;
            }
        }
    }
    vector<int> ans;
    start = 0;
    for(int i=0; i<txt.length(); i++) {
        if(txt[i] == s[start]) {
            if(start == n-1) {
                ans.push_back(i - n + 2);
                start = lps[start];
                i--;
            }
            else start++;
        }
        else {
            if(start == 0) continue;
            else {
                start = lps[start];
                i--;
            }
        }
    }
    return ans;
}

int main() {
    string txt = "ababbbab";
    string pattern = "ab";
    vector<int> v = KMPsearch(pattern, txt);
    for(int t : v) cout << t << " ";
}
