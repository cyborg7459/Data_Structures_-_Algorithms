// PS : Given 2 jugs of capacity n and m, find the minimum number of operations required to get exactly d litres of water
// Explanation : The condition for answer to exist is that d is divisible by gcd of n and m, and obviously, is smaller than the max of the 2. Now there would be 2 cases
// 1) We only transfer water from first jug to second
// 2) Vice versa
// Pick the best answer out of both

#include <bits/stdc++.h>
using namespace std;

int minSteps(int m, int n, int d) {
    int t = __gcd(n, m);
    if(d % t != 0) return -1;
    if(d > max(n, m)) return -1;
    int c1 = 0, c2 = 0;
    int a = 0, b = 0;
    while(true) {
        if(a==d || b==d) break;
        c1++;
        if(b == n) b = 0;
        else if(a == 0) a = m;
        else {
			int x = min(a, n-b);
            a -= x;
            b += x;
        }
    }
    a = 0, b = 0;
    while(true) {
        if(a==d || b==d) break;
        c2++;
        if(a == m) a = 0;
        else if(b == 0) b = n;
        else {
			int x = min(m-a, b);
            b -= x;
            a += x;
        }
    }
    return min(c1, c2);
}

int main() {
	cout << minSteps(3, 5, 4) << endl;
}
