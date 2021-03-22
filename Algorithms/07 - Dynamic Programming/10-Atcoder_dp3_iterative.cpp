#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define qtime long long q;\
                        cin >> q;\
                        while(q--)
#define nl "\n"
#define fi first
#define int long long
#define se second
#define loop(i,n) for(long long i=0;i<n;i++)
#define rloop(i,n) for(long long i=n-1; i>=0; i--)
#define print(x) {for(auto t : x)\
                            cout << t << " ";\
                            cout << "\n";}
#define printnl(x) for(auto t : x)\
                               cout << t << endl;
#define all(x) x.begin(), x.end()
#define o(x) cout << x << "\n"
#define i(x) cin >> x;
#define itr(x,a,b) x.begin()+a, x.begin()+b;
#define fast ios_base::sync_with_stdio(false);\
                     cin.tie(NULL);
#define inp(x) long long x;\
                        cin >> x
#define loop1(i,a,b) for(long long i=a ; i<=b ; i++)
#define itrloop(it,x) for(auto it=x.begin(); it!=x.end(); it++)
#define ritrloop(it, x) for(auto it=x.rbegin(); it!=x.rend(); it++)
#define INF 1000000007
#define PI 3.1415926536
#define flush cout.flush()
#define fileIO freopen("input.txt", "r", stdin);\
                       freopen("output.txt", "w", stdout);

typedef long long ll;
typedef vector<long long> vl;
typedef vector<int> vi;
typedef vector <string> vs;
typedef vector <char> vc;
typedef set<long long> sl;
typedef set<int> si;
typedef set <string> ss;
typedef set <char> sc;
typedef set <double> sd;
typedef map<long long, long long> ml;
typedef map<int,int> mi;
typedef map <string, int> ms;
typedef map <char,int> mc;

struct NumberTheory {
    static const ll mod = 1e9 + 7;
    vector<ll> factorial = {1}, factorialInv = {1};
    inline ll mult(ll a, ll b, ll m = mod) { return (a * b) % m; }
    inline ll norm(ll x) {
        x %= mod;
        if (x < 0) x += mod;
        return x;
    }
    inline ll div(ll a, ll b) { return mult(a, inv(b)); }
    inline ll sub(ll a, ll b) { return norm(a - b); }
    inline ll add(ll a, ll b) { return (a + b) % mod; }
    ll ncr(ll n, ll r) {
        assert(n >= 0);
        if (r < 0 || n < r) return 0;
        return mult(fac(n), mult(finv(r), finv(n - r)));
    }
    ll npr(ll n, ll r) {
        assert(n >= 0);
        if (r < 0 || n < r) return 0;
        return mult(fac(n), finv(n - r));
    }
    ll finv(ll n) {
        int last = factorialInv.size() - 1;
        if (last < n) {
            vector<ll> finv_temp(n - last);
            finv_temp[0] = inv(fac(n));
            for (int i = 1; i < (int)finv_temp.size(); i++) {
                finv_temp[i] = mult(finv_temp[i - 1], n - i + 1);
            }
            for (int i = finv_temp.size() - 1; i >= 0; i--) {
                factorialInv.push_back(finv_temp[i]);
            }
        }
        return factorialInv[n];
    }
    ll pow(ll x, ll e, ll m = mod) {
        if (e < 0) {
            x = inv(x);
            e *= -1;
        }
        ll res = 1;
        while (e > 0) {
            if (e & 1) res = mult(res, x, m);
            e = e >> 1;
            x = mult(x, x, m);
        }
        return res;
    }

    inline ll inv(ll x) {
        return pow(x, mod - 2);
    }

    ll fac(int n) {
        while ((int)factorial.size() <= n) {
            factorial.push_back(
                mult(factorial[factorial.size() - 1], factorial.size()));
        }
        return factorial[n];
    }
};

bool isprime(ll n) {
    for(ll i=sqrt(n); i>1; i--) {
        if(n%i==0)
            return false;
    }
    return true;
}

bool is_int(long double d) {
    if(d==ceil(d))
        return true;
    return false;
}

long long fact(ll x) {
    if(x==0 || x==1)
        return 1;
    else
        return x*fact(x-1);
}

long long gcd(ll n, ll m) {
    if (n%m ==0) return m;
    if (n < m) swap(n, m);
    while (m > 0) {
        n = n%m;
        swap(n, m);
    }
    return n;
}

bool isPowerOfTwo(int n)
{
    if(n==0)
        return false;
    return (ceil(log2(n)) == floor(log2(n)));
}

ll binary_search(ll x, ll low, ll high, ll arr[]) {
    if(low==high)
        return low;
    else {
        ll mid = (low+high)/2;
        if(arr[mid]==x)
            return mid;
        else if(arr[mid]>x)
            return binary_search(x, low, mid-1, arr);
        else
            return binary_search(x, mid+1, high, arr);
    }
    return -1;
}

vl primev;

void SieveOfEratosthenes(int n)
{
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }
    for (int p=2; p<=n; p++)
       if (prime[p])
         primev.pb(p);
}

ll sum_of_digits(ll n) {
    ll res{};
    while(n>0) {
        res+= (n%10);
        n/=10;
    }
    return res;
}

void solve() {
    int n;
	cin >> n;
	int arr[n][3], dp[n][3] = {};
	loop(i, n)
		loop(j, 3)
			cin >> arr[i][j];
	loop(i, 3)
		dp[0][i] = arr[0][i];
	for(int day=1; day<n; day++) {
		loop(i, 3) {
			loop(j, 3) {
				if(j != i)
					dp[day][j] = max(dp[day][j], dp[day-1][i] + arr[day][j]);
			}
		}
	}
	cout << max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2])) << nl;
}

signed main()
{
//    fileIO;
    fast;
//    SieveOfEratosthenes(1000000);
    int q = 1;
//    cin >> q;
    while(q--)
        solve();
}
