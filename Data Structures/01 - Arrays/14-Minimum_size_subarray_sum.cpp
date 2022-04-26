// Problem: https://leetcode.com/problems/minimum-size-subarray-sum/
// Solution: This is a standard 2-pointer approach problem. An important thing to note in 2-pointer approach is that for both the pointers, we should always first move the pointer and then perform the
// operation, and not the other way round. For eg - in the given problem, we are first incrementing end and then checking whether the subarray sum becomes greater than target. Same for the start pointer

#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
  int ans = 1000000;
  int start = 0, end = -1;
  int cur_sum = 0;
  while(true) {
      if(cur_sum < target) {
          end++;
          if(end == nums.size()) break;
          cur_sum += nums[end];
          if(cur_sum >= target) ans = min(ans, end-start+1);
      }
      else {
          cur_sum -= nums[start];
          start++;
          if(start > end) break;
          if(cur_sum >= target) ans = min(ans, end-start+1);
      }
  }
  if(ans == 1000000) return 0;
  return ans;
}

int main() {
  vector<int> nums = {2,5,4,3,6,7,3};
  int target = 11;
  cout << minSubArrayLen(target, nums);
}
