// PS : Given a 2D board and a word, find if the word exists in the grid. The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those
// horizontally or vertically neighboring. The cell itself does not count as an adjacent cell. The same letter cell may be used more than once.
// Explanation : This is a clear problem of graphs. The first thing which comes into mind is to do BFS to traverse the graph and find the string. For that we'll initially have pushed all the occurrences
// of first characters of the search string in the grid. In the queue, we keep track of the position, and the index of the search string we are at. If this index reaches the last character it means that
// we found the string. However, this method would give TLE. Since the start character is increasing at each step, it would be favourable to check more advanced strings, and hence, we use a priority_queue
// instead of queue, so that we always select the largest matching string available. This greatly reduces the number of traversals

#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int exist(vector<string> &A, string B) {
    priority_queue<pair<int, pair<int, int>>> q;
    for(int i=0; i<A.size(); i++) {
        string s = A[i];
        for(int j=0; j<s.length(); j++) {
            if(s[j] == B[0]) {
                q.push({0, {i, j}});
            }
        }
    }
    while(!q.empty()) {
        pair<int, pair<int, int>> p = q.top();
        q.pop();
        int last_idx = p.first;
        int x = p.second.first, y = p.second.second;
        if(last_idx == B.length()-1) return 1;
        for(pair<int, int> p : dir) {
            int x1 = x + p.first;
            int y1 = y + p.second;
            if(x1 < A.size() && y1 < A[x1].length()) {
                if(A[x1][y1] == B[last_idx + 1]) q.push({last_idx+1, {x1, y1}});
            }
        }
    }
    return 0;
}

int main() {
    vector<string> v = {"ABCE","SFCS","ADEE"};
    string s = "SEE";
    cout << exist(v, s);
}
