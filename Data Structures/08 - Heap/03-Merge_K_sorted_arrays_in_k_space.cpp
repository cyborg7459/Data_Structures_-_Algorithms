// PS : Given 'k' sorted arrays, we have to merge them into a single sorted vector using only O(k) extra space
// Explanation : The merging process is quite simple. The only catch here is the O(k) space complexity. We can solve this by using min heap, i.e. priority queue. First of all, we store the first elements of all the arrays
// then one by one choose the minimum using a priority_queue. Then we add the next element of that array into the heap again. Keep doing this until the heap does not get empty

#include <bits/stdc++.h>
using namespace std;

vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    for(int i=0; i<K; i++) {
        pq.push({arr[i][0], {i, 0}});
    }
    vector<int> ans;
    while(!pq.empty()) {
        pair<int, pair<int, int>> p = pq.top();
        pq.pop();
        ans.push_back(p.first);
        int arrayIdx = p.second.first;
        int idx = p.second.second;
        idx++;
        if(idx < K) {
            pq.push({arr[arrayIdx][idx], {arrayIdx, idx}});
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> arr = {
        {1,2,3,4},
        {1,2,3,4},
        {4,7,45,78},
        {3,5,8,55}
    };
    vector<int> ans = mergeKArrays(arr, arr.size());
    for(int t : ans) cout << t<< " ";
}
