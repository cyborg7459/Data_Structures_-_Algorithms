// Explanation : Tarjan's algorithm is used to detemine the presence of cycles and strongly connected components in a graph. The algorithm can be explained as follows :-
// 1) We require a stack, and 3 vectors. One for keeping in track the discovery time of nodes, another for keeping in track the low_link values, and the final one to keep in
// track whether a node is in the stack or not
// 2) We do depth-first search for the complete graph. The first time we encounter a node, we assign it a discovery time (with the help of a global variable), and push it in the
// stack. Now, the low_link value of any element is the valid element with the least discovery time that can be reached from that node. A valid element is one which is present
// in the stack, i.e. it is not already the part of some other strongly connected component. This is because we do not necessarily need to find the lowest reachable node from the
// current node. That won't give the correct answer.
// 3) These low_link values can be obtained in the following manner. For each node, once we ensure that all of it's neighbours have been visited, then in the return time we can
// minimize the low_link value to the neighbour's value if neighbour is a valid point and is not in some other SCC
// 4) If the low_link value of an element is equal to the discovery time, it means that the given node is the lowest node of it's strongly connected component. Hence, we start
// popping off elements from that node until we reach that node. By doing this, we remove all elements belonging in that strongly connected component from the stack and hence
// ensure that they won't come in some other. While removing, we also set the low value of all the elements removed to the discovery time of the current node (it is possible that
// this step did not happen during recursion)
// 5) Updating the sccCount counter can help us know the number of strongly connected components. If at the end, it is equal to the number of nodes, then it means that there are
// no strongly connected components
// 6) In case of finding the schedule for tasks, we have to take into consideration single element SCCs as well, i.e. if a node is connected to itself, then scheduling is not
// possible

#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100005];
int cur_disc = 0;
int sccCount = 0;

int disc[100005] = {};
int low[100005] = {};
bool isOnStack[100005] = {};

stack<int> st;
vector<vector<int>> scc;

void dfs(int node) {
    st.push(node);
    isOnStack[node] = true;
    disc[node] = cur_disc;
    low[node] = cur_disc;
    cur_disc++;

    for(int next : adj[node]) {
        if(disc[next] == -1) dfs(next);
        if(isOnStack[next]) low[node] = min(low[node], low[next]);
    }

    if(disc[node] == low[node]) {
        sccCount++;
        vector<int> temp;
        while(true) {
            int t = st.top();
            temp.push_back(t);
            st.pop();
            isOnStack[t] = false;
            low[t] = disc[node];
            if(t == node) break;
        }
        scc.push_back(temp);
    }
}

vector<int> TarjanSCC(int n) {
    vector<int> low_links(n);
    for(int i=0; i<n; i++) {
        if(disc[i] == -1) dfs(i);
    }
    for(int i=0; i<n; i++)
        low_links[i] = low[i];
    return low_links;
}

int main() {
    int n, e;
    cin >> n >> e;
    for(int i=0; i<n; i++) {
        disc[i] = -1;
        low[i] = 1000000007;
        isOnStack[i] = false;
    }
    for(int i=0; i<e; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    vector<int> low_links = TarjanSCC(n);
    if(sccCount == n)
        cout << "No cycles in the graph";
    else {
        cout << sccCount << " cycles in the graph.\nThe strongly connected components are :-\n";
        for(vector<int> v : scc) {
            for(int t : v)
                cout << t << " ";
            cout << endl;
        }
    }
}
