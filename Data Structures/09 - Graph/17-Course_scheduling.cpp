// PS : Given number of courses 'n' and a prerequisites list, which contains pairs of courses, where each pair {a, b} denotes that course b is a pre prerequisite for course a. We need to find out
// the order in which we can do the courses, or return an empty array if not possible

// Explanation : The order would be the topological sorting of the graphs formed. The cases where no schedule is possible are :-
// 1) A course is a pre-requisite for itself
// 2) There is a cycle in the graph, i.e. a strongly connected component
// Hence, we first implement Tarjan's algorithm to detemine the presence of SCCs. If not, then we print out the topological sorting

#include <bits/stdc++.h>
using namespace std;

int curDisc = 0;
int sccCount = 0;

int disc[2005];
int low[2005];
bool isOnStack[2005];

stack<int> st;

void dfs1(int node, vector<int> adj[]) {
    st.push(node);
    isOnStack[node] = true;
    disc[node] = curDisc;
    low[node] = curDisc;
    curDisc++;

    for(int next : adj[node]) {
        if(disc[next] == -1) dfs1(next, adj);
        if(isOnStack[next])
            low[node] = min(low[node], low[next]);
    }

    if(low[node] == disc[node]) {
        sccCount++;
        while(true) {
            int t = st.top();
            st.pop();
            isOnStack[t] = false;
            low[t] = low[node];
            if(t == node) break;
        }
    }
}

bool vis[2005];

void dfs2(int node, vector<int> &topSort, vector<int> adj[]) {
    vis[node] = true;
    for(int next : adj[node]) {
        if(!vis[next])
            dfs2(next, topSort, adj);
    }
    topSort.push_back(node);
}

vector<int> findOrder(int n, vector<vector<int>>& pre) {
    vector<int> adj[n];
    for(int i=0; i<pre.size(); i++) {
        int a = pre[i][0];
        int b = pre[i][1];
        if(a == b) return {};
        adj[b].push_back(a);
    }

    for(int i=0; i<n; i++) {
        disc[i] = -1;
        low[i] = 1000000007;
        isOnStack[i] = false;
    }

    for(int i=0; i<n; i++) {
        if(disc[i] == -1)
            dfs1(i, adj);
    }

    if(sccCount == n) {
        for(int i=0; i<n; i++)
            vis[i] = false;
        vector<int> topSort = {};

        for(int i=0; i<n; i++) {
            if(!vis[i])
                dfs2(i, topSort, adj);
        }

        reverse(topSort.begin(), topSort.end());
        return topSort;
    }
    else return {};
}

int main() {
    int n, e;
    cout << "Enter number of courses : ";
    cin >> n;
    cout << "Enter number of prerequisites : ";
    cin >> e;
    vector<vector<int>> pre;
    for(int i=0; i<n; i++) {
        cout << "Enter prerequisite " << i+1 << " : ";
        int a, b;
        cin >> a >> b;
        vector<int> temp;
        temp.push_back(a);
        temp.push_back(b);
        pre.push_back(temp);
    }

    vector<int> schedule = findOrder(n, pre);
    if(schedule.size() == 0)
        cout << "Cannot complete the courses\n";
    else {
        cout << "Courses can be done in the following order : ";
        for(int t : schedule)
            cout << t << " ";
    }
}
