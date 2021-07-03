// PS : Given 'K' sorted lists, we have to give the smallest range which contains at least one element from each of the list
// Explanation : Initially the range would be [min, max] where min and max are the minimum & maximum of the first elements of all lists. Now, we cannot decrease max because that would exclude one list, but we can
// increase min. Hence our goal is to increase min and much as we can. For this, we keep popping off the minimum element (found using a min heap) as long as we can. We stop popping off in any of these 2 cases :-
// 1) Removing the current element would lead to that array becoming empty
// 2) The next element of the current element is max, hence if we remove current element and then proceeed further than it, then current element would be excluded, and the elements larger than max are
// already excluded hence this array would be gone completely. Hence, we must stop after making min = current element

#include <bits/stdc++.h>
using namespace std;

pair<int,int> findSmallestRange(int arr[][1000], int n, int k) {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    int mn = 100000007, mx = -1;
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
        if(idx == n-1) break;
		if(arr[listnum][idx+1] > mx) break;
        pq.push({arr[listnum][idx+1], {listnum, idx+1}});
    }
    return {mn, mx};
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
