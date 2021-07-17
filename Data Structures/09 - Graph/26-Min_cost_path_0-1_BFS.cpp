// PS : You are given a AB character matrix named C. Every cell in C has a character U,R,L or D indicating up,right,left and down. Our target is to go from top left corner to the bottom right corner of
// the matrix. But there are some restrictions while moving along the matrix : If you follow what is written in the cell then you can move freely. But if you don't follow what is written in the cell
// then you have to pay 1 unit of cost. Eg: If a cell contains character U and you go right instead of Up you have to pay 1 unit of cost. So your task is to find the minimum cost to go from top-left
// corner to the bottom-right corner.

// Explanation : This is an example of a 0-1 BFS problem. A 0-1 BFS  is an optimization of the normal BFS wherein the edges are binary, i.e. either zero or one, and going through the zero edges is favourable.
// So instead of a queue, we take a deque, and if we encounter a 0 edge, push it to the front of the deque and if we encounter a 1 edge push it to the back. There is no visited array because the cost can
// be updated later to minimum. Hence, like in Dijkstra's, we push only when the given cost is less than the current cost. In this problem, one direction gives 0 cost and the other directions give a cost
// of 1, and hence this is a clear example of a 0-1 BFS. Rest of the implementation is simple

#include <bits/stdc++.h>
using namespace std;

map<char, pair<int, int>> mp = {
    {'U', {-1, 0}},
    {'D', {1, 0}},
    {'L', {0, -1}},
    {'R', {0, 1}}
};

vector<pair<int, int>> dir = {
    {-1, 0}, {1, 0}, {0, 1}, {0, -1}
};

int solve(int A, int B, vector<string> &C) {
    if(A == 1 && B==1) return 0;
    int cost[A][B];
    for(int i=0; i<A; i++) {
        for(int j=0; j<B; j++) {
            cost[i][j] = 1000000007;
        }
    }

    deque<pair<int, pair<int, int>>> q;
    q.push_front({0, {0, 0}});
    cost[0][0] = 0;

    while(!q.empty()) {
        pair<int, pair<int, int>> p = q.front();
        q.pop_front();
        int cur_cost = p.first;
        int x = p.second.first;
        int y = p.second.second;

        for(pair<int, int> p1 : dir) {
            int x1 = x + p1.first;
            int y1 = y + p1.second;
            if(x1 < 0 || x1 >= A || y1 < 0 || y1 >= B) continue;
            int new_cost;
            if(p1 == mp[C[x][y]]) new_cost = cur_cost;
            else new_cost = cur_cost + 1;
            if(new_cost < cost[x1][y1]) {
                cost[x1][y1] = new_cost;
                if(new_cost == cur_cost)
                    q.push_front({new_cost, {x1, y1}});
                else
                    q.push_back({new_cost, {x1, y1}});
            }
        }
    }

    return cost[A-1][B-1];
}

int main() {
    int A = 3, B = 3;
    vector<string> C = {"RRR", "DDD", "UUU"};
    cout << solve(A, B, C);
}
