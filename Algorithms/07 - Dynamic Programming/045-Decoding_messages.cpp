// PS : A message is encoded by replacing the characters with the numbers like a -> 1, b -> 2 .... We are given the encoded string and have to find out the total number of possible messages
// Explanation : First step is to remove all invalid strings, i.e. which contain consecutive zeroes, or substrings like 40, which can't be converted, or leading zeroes, etc. Then, the DP function
// checks the same, i.e. if it is possible to pick 2 characters at once, we pick 2 characters as well as 1 character and add the results. An important base case is that if the start character is
// zero then return zero. For example, in 1101, we cannot pick 11 from the start because that would leave us with 01 which is invalid. Hence, this base case handles such situations

#include <bits/stdc++.h>
using namespace std;

map<pair<string, int>, int> dp;

int countWays(string str, int start, int end) {
    if(str[start] == '0') return 0;
    if(start == end+1) return 1;
    if(start == end) return 1;
    if(dp.find({str, start}) != dp.end()) return dp[{str, start}];
    int res = 0;
    char a = str[start], b = str[start+1];
    if(a > '2' || (a == '2' && b > '6'))
        res = countWays(str, start+1, end) % 1000000007;
    else res =  (countWays(str, start+1, end) + countWays(str, start+2, end)) % 1000000007;
    dp.insert({{str, start}, res});
    return res;
}

int CountWays(string str) {
    if(str[0] == '0') return 0;

    for(int i=1; i<str.size(); i++) {
        if(str[i] == '0' && str[i-1] == '0') return 0;
        if(str[i] == '0' && str[i-1] > '2') return 0;
    }

    return countWays(str, 0, str.size()-1);
}

int main() {
    string s;
    cin >> s;
    cout << CountWays(s);
}
