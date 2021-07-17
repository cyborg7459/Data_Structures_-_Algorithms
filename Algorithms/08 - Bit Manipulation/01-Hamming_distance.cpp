// PS : Hamming distance of 2 integers is defined as the number of positions in which their bit differs in the binary representation. Given an array we have to calculate the sum of hamming distance for all
// (i, j)
// Explanation : What we can do is count the number of integers that have '1' at their ith bit. Suppose this is count, then the number of pairs would be count * (n - count) as for every number with bit '1', we
// can pair it with every number with bit '0'. Finally we also mulitply by 2 because the pairs are ordered. We do the same for all bits and add the answers

#include <bits/stdc++.h>
using namespace std;

#define inf 1000000007
int hammingDistance(const vector<int> &A) {
    int n = A.size();
    unsigned long long ans = 0;
    for(int i=0; i<32; i++) {
        unsigned long long cnt = 0;
        for(int num : A) {
            if(num & (1 << i)) {
                cnt++;
            }
        }
        ans += (2 * (cnt%inf * (n - cnt)%inf)%inf)%inf;
        ans %= inf;
    }
    return ans%inf;
}

int main() {
    vector<int> v = {2, 3, 8, 6, 7};
    cout << hammingDistance(v);
}
