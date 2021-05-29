// Problem : https://www.geeksforgeeks.org/minimum-cost-cut-board-squares/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define qtime long long q;\
			  cin >> q;\
			  while(q--)
#define loop(i,n)  for(long long i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(false);\
                     cin.tie(NULL);

void solve() {
	int n, m;
	cin >> n >> m;
	n--, m--;
	int a[n], b[m];
	int sum1 = 0, sum2 = 0;
	loop(i,n) {
		cin >> a[i];
		sum1 += a[i];
	}
	loop(i,m) {
		cin >> b[i];
		sum2 += b[i];
	}
	sort(a, a+n);
	reverse(a, a+n);
	sort(b, b + m);
	reverse(b, b + m);
	int i1 = 0, i2 = 0;
	int ans = 0;
	while(i1 < n && i2 < m) {
		if(a[i1] >= b[i2]) {
			ans += sum2 + a[i1];
			sum1 -= a[i1];
			i1++;
		}
		else {
			ans += sum1 + b[i2];
			sum2 -= b[i2];
			i2++;
		}
	}
	while(i1 < n) {
		ans += a[i1];
		i1++;
	}
	while(i2 < m) {
		ans += b[i2];
		i2++;
	}
	cout << ans;
}

signed main()
{
//    fileIO;
    fast;
//    SieveOfEratosthenes(1000000);
    int q = 1;
    cin >> q;
    while(q--)
        solve();
}
