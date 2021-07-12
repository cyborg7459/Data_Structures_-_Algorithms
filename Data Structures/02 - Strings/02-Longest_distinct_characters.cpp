// PS : Given a string, our goal is to find the longest substring which contains all distinct characters
// Explanation : We fix the start of the current substring and then keep a track of the latest occurrence of all character in the substring. If we encoutner a character which has it's latest occurrence after
// the start of the substring, it means that the character is repeated. Hence, we'll now shift the start to the character after that occurrence so that the addition of the latest character leads to all distinct
// only. Along with updating the start position, accordingly update the length of the current substring as well. In the cases where no dupication occurs, simply update answer to maximize it as well as update
// the occurrence position

#include<bits/stdc++.h>
using namespace std;

int arr[26] = {};

void init() {
	for(int i=0; i<26; i++) arr[i] = -1;
}

int longestSubstrDitinctChars (string s) {
	init();
    int start = 0, cur = 0, n = s.length();
    arr[s[0] - 97] = 0;
    int ans = 1, cnt = 1;
    while(cur < n) {
        cur++;
        if(cur < n) {
            int t = s[cur] - 97;
            if(arr[t] >= start) {
                ans = max(ans, cnt);
                start = arr[t] + 1;
				arr[t] = cur;
                cnt = cur - start + 1;
            } else {
                cnt++;
				arr[t] = cur;
            }
        }
    }
    ans = max(ans, cnt);
    return ans;
}

int main() {
    string S;
    cin >> S;
    cout << longestSubstrDitinctChars(S);
}
