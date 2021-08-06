// PS : Given 'K' sorted lists, we have to give the smallest range which contains at least one element from each of the list
// Explanation : Initially the range would be [min, max] where min and max are the minimum & maximum of the first elements of all lists. Now, we cannot decrease max because that would exclude one list, but we can
// increase min. Hence our goal is to increase min and much as we can. For this, we keep popping off the minimum element (found using a min heap) as long as we can. We stop popping off if the current minimum element
// is the last element of any of the arrays, because now if we increase min, then that arrray would be excluded.
// If the element next to the element we removed happens to be greater than max, then update max after updating the indexes because now we can move w.r.t. that element as the maximum element

#include <bits/stdc++.h>
using namespace std;

pair<int,int> findSmallestRange(int arr[][1000], int n, int k) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    int mn = 100000007, mx = -1;
    int mna = mn, mxa = mx;
    for(int i=0; i<k; i++) {
        pq.push({arr[i][0], {i, 0}});
        mn = min(mn, arr[i][0]);
        mx = max(mx, arr[i][0]);
    }
    while(true) {
        pair<int, pair<int, int>> p = pq.top();
        pq.pop();
        int num = p.first;
        int listnum = p.second.first;
        int idx = p.second.second;
        mn = num;
        if(abs(mx - mn) < abs(mxa - mna)) {
            mxa = mx;
            mna = mn;
        }
        if(idx == n-1) break;
		if(arr[listnum][idx+1] >= mx) {
            mx = arr[listnum][idx+1];
        };
        pq.push({arr[listnum][idx+1], {listnum, idx+1}});
    }
    return {mna, mxa};
}

int arr[1000][1000];
int main()
{
    int n, k;
    cin>>n>>k;
    pair<int,int> rangee;
    for(int i=0; i<k; i++)
        for(int j=0; j<n; j++)
            cin>>arr[i][j];
    rangee = findSmallestRange(arr, n, k);
    cout<<rangee.first<<" "<<rangee.second<<"\n";
}
