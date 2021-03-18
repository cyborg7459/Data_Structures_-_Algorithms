// Problem : https://practice.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/1/?track=md-arrays&batchId=144#
// Here we will use the technique of storing 2 elements in a single array position. However for this we have to make sure that the largest element is small enough so that n^2 doensn't exceed the range of
// int or long long whatever we are using. First of all we'll decrease all elemtns by 1 for 2 reasons - (A) They can be directly used as indexes (B) All elements become strictly smaller than n
// Now for each position, whichever number is originally present on it, which we can get by doing v[i]%n, we'll go to it's index and increase it by n, hence increasing the count by 1
// At the end we'll divide the entire array by n so that we get the 2nd number stored for all of them, i.e. the freuquency count

#include <bits/stdc++.h>
using namespace std;

void countFrequencies(vector<int> &v, int n) {
    for(int i=0; i<n; i++) v[i]--;
    for(int i=0; i<n; i++) v[v[i]%n]+=n;
    for(int i=0; i<n; i++) v[i]/=n;
}

int main() {
    vector<int> v = {1,1,2,4,5,6,1,8};
    countFrequencies(v, 8);
    for(int i=0; i<8; i++)
        cout << v[i] << " ";
}
