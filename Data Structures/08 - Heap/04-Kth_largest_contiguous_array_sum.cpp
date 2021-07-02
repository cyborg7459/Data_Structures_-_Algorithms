// PS : Given an array, out of all the contiguous subarrays sum, return the Kth largest sum of elements
// Explanation : The brute force solution to this problem is of O(n^3) time complexity as we find the sum of all subarrays and then store them in an array, finally sorting and finding the Kth
// largest. If we use prefix sum array instead, then we can reduce the time complexity to O(n^2), but the space complexity still remains to O(n). We can reduce the space complexity further by
// using a priority_queue. Basically the goal is to store the K largest subarray sums in the priority_queue and then return the minumum of them. The former can be done easily since all we need
// is to keep a min heap of size 'k'. If the current element is greater than the smallest element of the priority_queue, it means that it belongs in the k largest elements and the latter does not.
// Hence we'll simply pop the top and push the new element
// NOTE : Solve the Kth smallest and Kth largest problems like this as well
// V.V.V.IMPORTANT : THIS METHOD OF USING MIN HEAP TO STORE K LARGEST AND MAX HEAP TO STORE K SMALLEST IS ONE OF THE MOST IMPORTANT CONCEPTS IN HEAP AND IS USED IN SEVERAL QUESTIONS LIKE KTH LARGEST
// IN A STREAM, MEDIAN OF A STREAM, ETC

#include <bits/stdc++.h>
using namespace std;

int KthLargestContiguousArraySum(vector<int> v, int k) {
    vector<int> pre = {0};
    int sum = 0;
    for(int i=0; i<v.size(); i++) {
        sum += v[i];
        pre.push_back(sum);
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=1; i<=v.size(); i++) {
        for(int j=i; j<=v.size(); j++) {
            int sum = pre[j] - pre[i-1];
            if(pq.size() < k) pq.push(sum);
            else {
                if(pq.top() < sum) {
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }
    return pq.top();
}

int main() {
    vector<int> v = {10, -10, 20, -40};
    int num = 6;
    cout << KthLargestContiguousArraySum(v, num);
}
