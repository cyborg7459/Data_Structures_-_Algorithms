// Problem: https://leetcode.com/problems/majority-element/
// Solution: Majority element problem can be solved using Boyer Moore Voting Algorihtm, the basis of which is that if an element is present in majority, all other elements must be in minority (obviously).
// What we do in this algorithm is that we choose a candidate element and start traversing the array. If we encounter the candidate, we increment the number of votes and if we encounter some other number,
// we decrement the votes. Now, if the number of votes becomes equal to zero, it means that the current candidate was not the majority element. Now we'll take the current element as the candidate and proceed.
// Why this algorithm works - Suppose the majority elements are concentrated towards the beginning, then the votes would increment so much that the other elements (in minority) won't be able to make it zero.
// If the majority elements are concentrated towards the end, then they will make the votes of the ongoing candidate to zero and would then become candidate themselves.
// At the end, we need one more traversal to confirm whether the element is actually majority (not in this question because here we are guaranteed that a majority element exists). Hence, the algorithm works in
// O(n) time (2 traversals) and O(1) extra space

#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
  int cand = -1, votes = 0;
  for(int num : nums) {
      if(cand == -1) cand = num;
      if(num == cand) votes++;
      else {
          votes--;
          if(votes == 0) {
              cand = num;
              votes = 1;
          }
      }
  }
  return cand;
}

int main() {
  vector<int> v = {1,2,3,4,4,2,2,2,3,2,2};
  cout << majorityElement(v);
}
