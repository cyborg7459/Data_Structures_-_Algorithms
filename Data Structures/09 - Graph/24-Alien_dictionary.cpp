// PS : Given the alphabetical order of words in an alien language, we need to find the order of the letters in the alphabet for that language
// Explanation : This problem can be solved using topoligical sorting, as the required order would be the topoligical sorting of the characters. Creating the graph is the main catch here. We need to see consecutive
// strings, and then the first position where they differ can be used to create the graph

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[26];
bool vis[26];

bool isInCycle(int num, vector<bool>&vis, vector<bool> &isOnStack) {
    vis[num] = true;
    isOnStack[num] = true;

    for(int next : adj[num]) {
        if(!vis[next]) {
            if(isInCycle(next, vis, isOnStack)) return true;
        }
        else if(isOnStack[next]) return true;
    }

    isOnStack[num] = false;
    return false;
}

void dfs(int cur, vector<int> &v) {
    vis[cur] = true;
    for(int next : adj[cur]) {
        if(!vis[next]) dfs(next, v);
    }
    v.push_back(cur);
}

string findOrder(string dict[], int N, int K) {
    for(int i=0; i<N-1; i++) {
        string s1 = dict[i];
        string s2 = dict[i+1];
        int idx1 = 0, idx2 = 0;
        while(idx1<s1.length() && idx2<s2.length()) {
            char c1 = s1[idx1++];
            char c2 = s2[idx2++];
            if(c1 == c2) continue;
            else {
                adj[c1-'a'].push_back(c2-'a');
                break;
            }
        }
    }

    for(int i=0; i<26; i++) {
        sort(adj[i].begin(), adj[i].end());
        auto it = unique(adj[i].begin(), adj[i].end());
        adj[i].resize(it - adj[i].begin());
    }

    vector<bool> vis1(K, false);
    vector<bool> isOnStack(K, false);
    for(int i=0; i<K; i++) {
        if(isInCycle(i, vis1, isOnStack)) {
            return "";
        }
    }

    memset(vis, false, sizeof vis);
    vector<int> topsort;
    for(int i=0; i<K; i++) {
        if(!vis[i]) dfs(i, topsort);
    }
    reverse(topsort.begin(), topsort.end());

    string ans;
    for(int i=0; i<K; i++) {
        char c = topsort[i] + 'a';
        ans.push_back(c);
    }
    return ans;
}

int main() {
    int n = 5, k = 4;
    string dict[n] = {"baa","abcd","abca","cab","cad"};
    string ans = findOrder(dict, n, k);
    if(ans == "") cout << "No order possible";
    else cout << ans;
}
