#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1000000007

signed main()
{
	int n;
	cin >> n;
	int arr[n][3];
	for(int i=0; i<n; i++)
		for(int j=0; j<3; j++)
			cin >> arr[i][j];
	int dp[n][3];
	for(int i=0; i<3; i++)
		dp[0][i] = arr[0][i];
	for(int i=1; i<n; i++){
		for(int j=0; j<3; j++) {
			if(j==0)
				dp[i][j] = arr[i][j] + max(dp[i-1][1], dp[i-1][2]);
			else if(j==1)
				dp[i][j] = arr[i][j] + max(dp[i-1][0], dp[i-1][2]);
			else
				dp[i][j] = arr[i][j] + max(dp[i-1][0], dp[i-1][1]);
		}
	}
	cout << max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2])) << "\n";
}
