#include <bits/stdc++.h>
using namespace std;

int main() {
	for(int n=1; n<=100; n++) {
	int sum = (n*(n+1))/2;
    cout << n << " : ";
	if(sum % 2 == 1) cout << 0 << endl;
	else {
        sum/=2;
		long long dp[sum + 1] = {};
		dp[1] = 1;
		for(int i=2; i<=n; i++) {
			for(int j=sum; j>=0; j--) {
				if(j - i >=0) {
					dp[j] += dp[j-i];
					dp[j] %= 1000000007;
				}
			}
		}
		cout << dp[sum] << endl;
	}}
}
