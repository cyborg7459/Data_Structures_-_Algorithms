// PS : Return a vector containing all permutations of a given string
// Explanation : We can solve the given problem using backtracking. Complexity of this solution is O(n * n!) because a total of n! permutations are possible, and in each permutation we are scanning the
// n-length visited array

#include <bits/stdc++.h>
using namespace std;

vector<string> res;
void get_permutations(vector<int> &visited, string &cur, string s) {
    if(cur.length() == s.length()) {
        res.push_back(cur);
        return;
    }
    for(int i = 0; i < visited.size(); i++) {
        if(visited[i] == 0) {
            cur.push_back(s[i]);
            visited[i] = 1;
            get_permutations(visited, cur, s);
            cur.pop_back();
            visited[i] = 0;
        }
    }
}

int main() {
    string s = "abcd";
    string cur = "";
    vector<int> visited(s.length(), 0);
    get_permutations(visited, cur, s);
    for(string s : res)
        cout << s << " ";
}
