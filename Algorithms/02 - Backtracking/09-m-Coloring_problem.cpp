// PS : Given a graph, we have to determine whether we can color the nodes using 'm' colors under the condition that no 2 connected nodes are colored using the same color
// Explanation : This is a direct question of backtracking, wherein we assign each node a valid color (a color is valid for a node if none of the already colored connected nodes have that same color).
// After coloring the node, we move on to the uncolored connected nodes recursively. If all of them return true, then this color is possible and we return true, else we backtrack and put the color back
// as -1. Since the graph can be disjoint, hence we have to run recursive function starting from any particular node for each connected segment of the graph. This can be done easily since we're having
// a vector keeping track of colors, so it can be used as a visited vector as well

#include <bits/stdc++.h>
using namespace std;

bool canColor(int node, int cr, vector<int> &color, bool graph[101][101], int V) {
    for(int i = 0; i<V; i++) {
        if(graph[node][i] && color[i] == cr) return false;
    }
    return true;
}

bool colorNodes(int node, int m, int V, bool graph[101][101], vector<int> &color) {
    for(int cr = 0; cr < m; cr++) {
        if(canColor(node, cr, color, graph, V)) {
            color[node] = cr;
            bool b = true;
            for(int i=0; i<V; i++) {
                if(graph[node][i] && color[i] == -1) {
                    b = b && colorNodes(i, m, V, graph, color);
                    if(!b) break;
                }
            }
            if(b) return true;
            else {
                color[node] = -1;
            }
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int V) {
    vector<int> color(V, -1);
    vector<int> startNodes;
    bool ans = true;
    for(int i=0; i<V; i++) {
        if(color[i] == -1) {
            ans = ans && colorNodes(i, m, V, graph, color);
            if(!ans) return false;
        }
    }
    return ans;
}

int main() {
    int V, m, e;
    cout << "Enter number of nodes : ";
    cin >> V;
    cout << "Enter number of allowed colors : ";
    cin >> m;
    bool graph[101][101] = {};
    cout << "Enter number of edges : ";
    cin >> e;
    for(int i=0; i<e; i++) {
        cout << "Enter nodes of edge " << i + 1 << " (Value lies b/w 0 to 100) : ";
        int a, b;
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
    }
    bool b = graphColoring(graph, m ,V);
    cout << boolalpha << b;
}
