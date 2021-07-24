// PS : We have to interchange all occurrences of any 2 characters from a string in such a way that the string becomes lexicographically as small as possible
// Explanation : First have a second string and sort it. Now, what we have to do is check the first favourable pair from the start, because the closer to the start we make the swap, the more
// lexicographically smaller the string is. Now, how ti decide a favourable pair? A pair is favourable is char2 is the smallest character whose first occurrence lies strictly after the current
// character. Also, it should be smaller that the current character as well. The first condition is necessary because if the character has occurrenced before, then while interchanging, we'll
// change the earlier occurrences to a larger character, hence lexicographically increasing the string

#include <bits/stdc++.h>
using namespace std;

string chooseandswap(string a){
    char c1, c2;
    int visited[26] = {};
    string s = a;
    sort(s.begin(), s.end());
    int i1 = 0, i2 = 0;
    while(i1 < a.length() && i2 < a.length()) {
        visited[a[i1]-97] = 1;
        if(s[i2] >= a[i1])
            i1++;
        else if(visited[s[i2] - 97] == 1)
            i2++;
        else {
            c1 = a[i1];
            c2 = s[i2];
            break;
        }
    }
    for(int i=0; i<a.length(); i++) {
        if(a[i] == c1) a[i] = c2;
        else if(a[i] == c2) a[i] = c1;
    }
    return a;
}

int main() {
    cout << chooseandswap("accaabdb");
}
