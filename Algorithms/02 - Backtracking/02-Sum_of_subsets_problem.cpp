#include <bits/stdc++.h>
using namespace std;

vector<int> v, subset;
int n, sum;
void search(int cur) {
    if(cur == n) {
        int temp = 0;
        for(int i=0; i<subset.size(); i++)
            temp += v[subset[i]];
        if(temp == sum) {
            for(int i=0; i<subset.size(); i++)
                cout << v[subset[i]] << " ";
            cout << "\n";
        }
    } else {
        search(cur+1);
        subset.push_back(cur);
        search(cur+1);
        subset.pop_back();
    }
}

int main() {
    cout << "Enter number of elements : ";
    cin >> n;
    cout << "Enter desired sum : ";
    cin >> sum;
    cout << "Enter elements : ";
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    search(0);
}
