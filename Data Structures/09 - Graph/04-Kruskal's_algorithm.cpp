#include <bits/stdc++.h>
using namespace std;

int edges[3][9] = {
    {1,1,2,2,3,4,4,5,5},
    {2,6,3,7,4,5,7,6,7},
    {25,5,12,10,8,16,14,20,18}
};

int set_arr[8] = {0,-1,-1,-1,-1,-1,-1,-1};
int included[9] = {};
int t[2][6];

int find_min() {
    int min = 1000000000, idx;
    for(int i=0; i<9; i++) {
        if(included[i] == 0 && edges[2][i] < min) {
            min = edges[2][i];
            idx = i;
        }
    }
    return idx;
}

int find_parent(int i) {
    while(set_arr[i] > 0)
        i = set_arr[i];
    return i;
}

void union_set(int a, int b) {
    if(set_arr[a] <= set_arr[b]) {
        set_arr[a] += set_arr[b];
        set_arr[b] = a;
    }
    else {
        set_arr[b] += set_arr[a];
        set_arr[a] = b;
    }
}

int main() {
    int i = 0;
    while(i < 6) {
        int idx = find_min();
        included[idx] = 1;
        int a = edges[0][idx], b = edges[1][idx];
        if(find_parent(a) == find_parent(b))
            continue;
        else {
            t[0][i] = a;
            t[1][i] = b;
            a = find_parent(a), b = find_parent(b);
            union_set(a,b);
            i++;
        }
    }
    for(int i=0; i<6; i++)
        cout << t[0][i] << " " << t[1][i] << "\n";
}
