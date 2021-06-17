// Explanation : Intuition is needed in this question. The first element will always be in this series, because there is no way to find a subsequence leaving out the first element such that it is larger
// than what could've been acheived using the first element. Suppose that leaving out the first element, we get an alternating subsequence which starts with increase. Now suppose first element of this
// subsequence is greater than nums[0] then we can simply replace it with nums[0] and get the same size subsequence. If that element is smaller, then we can infact increase the subsequence size by 1 by
// also including the first element. Similarly, we can do the same in case the subsequence had started with a decrease.
// Now what we do is keep boolean to keep track of whether we wish to desire an increase or a decrease in the given step. The initial value of this boolean can be set by seeing the first and second element
// of the array (for this we first need to remove consecutve same elements because they might lead to problems, especially in this initialisation step). We also keep have mx and mn variables to keep in track
// the value of hills and values. Now suppose we are on increasing step, and the number we encounter is greater than mn, hence we got out required term and our subsequence increases in length by 1. However,
// if the value is less than mn, what we can do is update mn. This does not disturb the already formed subsequence as the last step was a decrease and hence all we're doing is increasing the magnitude of
// decrease. Why this is important is because it increases the possible values of peaks for increasing.
// Same logic can be applied to decrease step as well

#include <bits/stdc++.h>
using namespace std;

int AlternatingaMaxLength(vector<int>&nums){
    auto it = unique(nums.begin(), nums.end());
    nums.resize(it - nums.begin());
    int n = nums.size();
    if(n == 1) return 1;
    int ans = 1;
    int mn = nums[0], mx = nums[0];
    bool b = (nums[1] > nums[0]);
    for(int i=1; i<n; i++) {
        if(b && nums[i] <= mn) mn = nums[i];
        else if(!b && nums[i] >= mx) mx = nums[i];
        else {
            ans++;
            if(b) mx = nums[i];
            else mn = nums[i];
            b = !b;
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {1,1,1,17,17,5,10,13,15,10,5,16,8};
    cout << AlternatingaMaxLength(nums);
}
