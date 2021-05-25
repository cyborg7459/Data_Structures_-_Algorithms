#include <bits/stdc++.h>
using namespace std;

int min_sprinklers(int gallery[], int n) {
    vector<int> next(n, -1);
    for(int i=0; i<n; i++) {
        int x = gallery[i];
        if(x > -1) {
            int start = max(0, i-x);
            for(int j=start; j<=min(n-1,i+x); j++)
                next[j] = max(next[j], i+x+1);
        }
    }
    int i = 0, ans = 0;
    while(i < n) {
        ans++;
        if(next[i] == -1) return -1;
        else i = next[i];
    }
    return ans;
}

int main() {
    int gallery[9] = {2, 3, 4, -1, 0, 0, 0, 0, 0};
    cout << min_sprinklers(gallery, 9);
}
