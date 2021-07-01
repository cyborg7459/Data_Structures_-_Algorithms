// PS : Given a string, we need to reorganise the characters in it such that no 2 adjacent characters are the same
// Explanation : First step is to keep a count of all the character that occur in the string. If any of them exceeds more than half of the total number of characters, then obviously it is not
// possible to rearrange the string as stated. In other cases, first create a temporary string which has the characters in decreasing order of the number of occurrences. Now from this string
// we can pick up characters and put them in alternating positions in the main string

#include <bits/stdc++.h>
using namespace std;

string reorganizeString(string s) {
    int arr[26] = {};
    for(int i=0; i<s.length(); i++) {
        char c = s[i];
        arr[c - 'a']++;
        if(arr[c - 'a'] > ceil((double)s.length()/2)) {
            string res = "";
            return res;
        }
    }

    priority_queue<pair<int, int>> pq;
    for(int i=0; i<26; i++) {
        if(arr[i] > 0) {
            pq.push({arr[i], i});
        }
    }

    string temp;
    while(!pq.empty()) {
        pair<int, int> p = pq.top();
        pq.pop();
        char c = 'a' + p.second;
        int num = p.first;
        while(num--) temp.push_back(c);
    }

    string ans(temp.length(), '*');
    int idx = 0;
    for(int i=0; i<ans.length(); i+=2) ans[i] = temp[idx++];
    for(int i=1; i<ans.length(); i+=2) ans[i] = temp[idx++];

    return ans;
}

int main() {
    string s = "vaavvvr";
    cout << reorganizeString(s);
}
