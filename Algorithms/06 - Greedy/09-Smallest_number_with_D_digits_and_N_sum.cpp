// PS : Our goal is to find the smallest number with 'D' digits whose sum of digits is equal to 'S'
// Explanation : First off, we handle all the base cases of number not being possible, or it being zero. Now, we'll start moving from left to right, i.e. from the position of maximum
// place value. Hence our goal should be to minimize the current digit at the expense of increasing the subsequent digits. First of all, we'll check whether the current digit can be zero
// or not. This can be found out if all the subsequent digits are 9, and they add up to be smaller than the remaining sum, then obviously we cannot take the current digit as zero. In this
// case, we'll put all the subsequent digits 9 so that the current digit becomes minimum possible. If the sum had been greater than the remaining sum, it means that we can put the current
// digit as zero (however if the string is empty, we'll put it 1, as leading zeroes are not allowed)

#include <bits/stdc++.h>
using namespace std;

string smallestNumber(int S, int D){
    if(S > 9*D || (D > 1 && S==0)) return "-1";
    if(D == 1 && S == 0) return "0";
    string ans;
    while(D != 0) {
        if(D == 1)
            ans.push_back(to_string(S)[0]);
        else {
            int k = (D-1)*9;
            if(k >= S) {
                if(ans.length() == 0) {
                    ans.push_back('1');
                    S--;
                }
                else ans.push_back('0');
            } else {
                int diff = S - k;
                ans.push_back(to_string(diff)[0]);
                S -= diff;
            }
        }
        D--;
    }
    return ans;
}

int main() {
    cout << smallestNumber(14, 7);
}
