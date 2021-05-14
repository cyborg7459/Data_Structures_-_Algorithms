// PS : M[i][j] represents whether person 'i' knows person 'j' or not. A person is a celebrity if everyone knows him but he does not know anyone
// We have to find the index of the celebrity in O(1)

// Solution : The simple solution of the problem would've been brute force in O(n^2). However, we need to solve this in linear time. For that, we'll
// compare 2 people at a time and of those 2 people, at least one would necessarily not be a celebrity. Hence, we keep eliminating people, and at the end
// we're either left with no people (indicating that there is no celebrity), or a single person. Now, we cannot directly declare that person as a
// celebrity as we don't know whether that person is known by the ones eliminated in the earlier stages. Hence we'll check all other people w.r.t that
// person, that he should not know them and they should know him. If no discrepancy, then the given person is a celebrity


#include <bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int>>& M, int n)  {
    stack<int> st;
    for(int i=0; i<n; i++) {
        if(st.empty()) {
            st.push(i);
        }
        else {
            int j = st.top();
            if(M[i][j] == 0 && M[j][i] == 0) st.pop();
            else if(M[i][j] == 1 && M[j][i] == 1) st.pop();
            else if(M[i][j] == 0 && M[j][i] == 1) {
                st.pop();
                st.push(i);
            }
        }
    }
    if(st.empty()) return -1;
    int idx = st.top();
    for(int i=0; i<n; i++) {
        if(i == idx) continue;
        if(M[i][idx] == 0 || M[idx][i] == 1) return -1;
    }
    return idx;
}

int main() {
    vector<vector<int>> M;
    M.push_back(vector<int> {0,0,1});
    M.push_back(vector<int> {0,0,1});
    M.push_back(vector<int> {1,0,0});
    cout << celebrity(M, 3);
}
