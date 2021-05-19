// PS : We have to find out the maximum element in all k-length subarrays in the given subarrays
// Solution : The given problem can be solved with the help of a deque, as the solution requires us to remove elements from both, the back and front. We'll create a deque storing pairs
// of ints as we need to keep track of the index along with the element. We'll now start filling the ans array. First of all, start with the initial 'k' elements and then one by one keep
// adding the next elements into the deque. This addition into the deque is where the logic would be implemented. On close observation, we can conclude that once an element greater than
// a given element has arrived in the sequence, then the earlier element would no longer be the answer to any of the subsequent subarrays because a greater element has already entered the
// window, and since it has entered later than the first element, it won't leave before that. Hence, upon addition of any element, we keep popping off smaller elements from the back. Also,
// we pop off those elements from the front who have now exited the window, i.e. the absolute difference of the index of that element and the latest added element is >= k. After making these
// 2 removals, we can be sure that the front of the deque is the greatest element in the current k-sized window, and hence we can push it to the answer array

#include <bits/stdc++.h>
using namespace std;

vector <int> max_of_subarrays(int *arr, int n, int k)
{
    vector <int> res;
    deque<pair<int, int>> q;
    for(int i=0; i<k; i++) {
        while(!q.empty() && q.back().first <= arr[i])
            q.pop_back();
        q.push_back({arr[i], i});
    }
    res.push_back(q.front().first);

    for(int i=k; i<n; i++) {
        while(!q.empty() && i - q.front().second >= k)
            q.pop_front();
        while(!q.empty() && q.back().first <= arr[i])
            q.pop_back();
        q.push_back({arr[i], i});
        res.push_back(q.front().first);
    }

    return res;
}

int main() {
    int n = 10, k = 4;
    int arr[n] = {8,5,10,7,9,4,15,12,90,13};
    vector <int> ans = max_of_subarrays(arr, n, k);
    for(int t : ans)
        cout << t << " ";
}
