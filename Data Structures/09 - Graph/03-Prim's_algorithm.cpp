#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000

int cost[8][8] = {
    {INF, INF, INF, INF, INF, INF, INF, INF},
    {INF, INF, 25, INF, INF, INF, 5, INF},
    {INF, 25, INF, 12, INF, INF, INF, 10},
    {INF, INF, 12, INF, 8, INF, INF, INF},
    {INF, INF, INF, 8, INF, 16, INF, 14},
    {INF, INF, INF, INF, 16, INF, 20, 18},
    {INF, 5, INF, INF, INF, 20, INF, INF},
    {INF, INF, 10, INF, 14, 18, INF, INF}
};

int near[8] = {INF, INF, INF, INF, INF, INF, INF, INF};
int t[2][6];

int main() {
    int min = INF, u, v;
    for(int i=1; i<=7; i++) {
        for(int j=i; j<=7; j++) {
            if(cost[i][j] < min) {
                min = cost[i][j];
                u = i, v = j;
            }
        }
    }
    t[0][0] = u, t[0][1] = v;
    near[u] = 0, near[v] = 0;
    for(int i=1; i<=7; i++) {
        if(near[i]!=0) {
            if(cost[i][u] < cost[i][v])
                near[i] = u;
            else
                near[i] = v;
        }
    }
    for(int i=1; i<=6; i++) {
        int min = INF, idx;
        for(int i=1; i<=7; i++) {
            if(near[i]!=0) {
                if(cost[i][near[i]] < min) {
                    min = cost[i][near[i]];
                    idx = i;
                }
            }
        }
        t[i][0] = idx;
        t[i][1] = near[idx];
        near[idx] = 0;
        for(int i=1; i<=7; i++) {
            if(near[i]!=0) {
                if(cost[i][idx] <= cost[i][near[i]])
                    near[i] = idx;
            }
        }
    }
    for(int i=0; i<=5; i++)
        cout << t[i][0] << " " << t[i][1] << "\n";
}
