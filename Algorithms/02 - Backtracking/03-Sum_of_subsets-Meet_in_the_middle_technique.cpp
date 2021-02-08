#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> subset, sum1, sum2;
map <int, int> sum_1, sum_2;
void search(int k, vector<int> &v, map<int, int> &sum) {
    if(k==n) {
        int temp = 0;
        for(int i=0; i<subset.size(); i++)
            temp += v[subset[i]];
        if(sum.find(temp) == sum.end())
            sum.insert({temp, 1});
        else
            sum[temp]++;
    } else {
        search(k+1, v, sum);
        subset.push_back(k);
        search(k+1, v, sum);
        subset.pop_back();
    }
}

int main() {
    int num, sum;
    cin >> num >> sum;
    vector<int> v1, v2;
    for(int i=0; i<num; i++){
        int x;
        cin >> x;
        if(i<num/2)
            v1.push_back(x);
        else
            v2.push_back(x);
    }
    n = num/2;
    search(0, v1, sum_1);
    subset.clear();
    n = num - n;
    search(0, v2, sum_2);
    // for(auto it = sum_1.begin(); it!= sum_1.end(); it++)
    //     cout << it->first << " : " << it->second << "\n";
    // cout << "\n";
    // for(auto it = sum_2.begin(); it!= sum_2.end(); it++)
    //     cout << it->first << " : " << it->second << "\n";
    auto it1 = sum_1.begin(), it2 = --sum_2.end();
    int res = 0;
    while(it1!= sum_1.end() && it2!= --sum_2.begin()) {
        int temp = it1->first + it2->first;
        if(temp == sum) {
            res += it1->second * it2->second;
            it1++;
        }
        else if(temp < sum)
            it1++;
        else
            it2--;
    }
    cout << res << "\n";
}
