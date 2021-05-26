// PS : There are given N ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to sum of their lengths.
// The task is to connect the ropes with minimum cost.
// Explanation : At each step, the most optimal choice would be to pick the 2 smallest ropes and join them together. Hence, we'll use priority queue

#include <bits/stdc++.h>
using namespace std;

long long minCost(long long arr[], long long n) {
    long long res = 0;
    priority_queue <long long, vector<long long>, greater<long long> > pq;
    for(int i=0; i<n; i++)
        pq.push(arr[i]);
    while(pq.size() > 1) {
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();
        res+=(a+b);
        pq.push(a+b);
    }
    return res;
}

int main() {
    long long n;
    cin >> n;
    long long i, a[n];
    for (i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << minCost(a, n);
    return 0;
}
