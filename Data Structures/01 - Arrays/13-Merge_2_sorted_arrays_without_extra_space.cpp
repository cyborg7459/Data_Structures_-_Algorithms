// Problem: https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1#
// Solution: IMPORTANT PATTERN TO NOTICE - In this questions, we cannot use extra space. However, our work would've been simple had we been allowed to use an extra array of size equal to the total number of
// elements. This type of problem can be solved by using the technique of storing 2 elements at same position in an array. Hence now, this is a simple merging problem

#include <bits/stdc++.h>
using namespace std;

void merge(int arr1[], int arr2[], int n, int m) {
    int mx = -1;
    for(int i=0; i<n; i++) mx = max(mx, arr1[i]);
    for(int j=0; j<m; j++) mx = max(mx, arr2[j]);
    mx++;
    int i1 = 0, i2 = 0, i = 0;
    bool check = true;
    while(i1<n && i2<m) {
        int a = arr1[i1]%mx;
        int b = arr2[i2]%mx;
        if(a < b) {
            if(check) arr1[i] += a*mx;
            else arr2[i] += a*mx;
            i1++;
        }
        else {
            if(check) arr1[i] += b*mx;
            else arr2[i] += b*mx;
            i2++;
        }
        i++;
        if(i==n && check) {
            check = false;
            i=0;
        }
    }
    while(i1<n) {
        if(check) arr1[i] += (arr1[i1]%mx)*mx;
        else arr2[i] += (arr1[i1]%mx)*mx;
        i1++;
        i++;
        if(i==n && check) {
            check = false;
            i = 0;
        }
    }
    while(i2<m) {
        if(check) arr1[i] += (arr2[i2]%mx)*mx;
        else arr2[i] += (arr2[i2]%mx)*mx;
        i2++;
        i++;
        if(i==n && check) {
            check = false;
            i = 0;
        }
    }
    for(int i=0; i<n; i++) arr1[i]/=mx;
    for(int i=0; i<m; i++) arr2[i]/=mx;
}

int main() {
  int arr1[5] = {5,7,9,11,18};
  int arr2[7] = {2,3,8,13,17,18,20};
  merge(arr1, arr2, 5, 7);
  for(int t : arr1) cout << t << " ";
  for(int t : arr2) cout << t << " ";
}
