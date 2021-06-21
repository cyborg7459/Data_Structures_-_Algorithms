// PS : https://leetcode.com/problems/evaluate-division/
// Explanation : In the given problem, we need to chain on equations until we get the desirable results, i.e. suppose we need a/e, then we need to multiply a/b, b/c, c/d, and d/e. Thus, this can be solved
// using dfs. The initialization steps include filling a map with appropriate data form. Now, to find x/y we have to reach from the numerator of x and denominator of y. Suppose we find numerator of x and
// denominator of z, and then find numerator of z and denominator of y, then also out goal is fulfilled. Hence, start the dfs with the 2 strings as parameters, and keep changing the numerator to current
// denominator until the ultimate denominator is achieved. In case a path does have such a value, then return a very high value so that at the return time we can detect that no path was possible. If the
// ultimate denominator was found after some steps, then we need to multiply all the values in that path, which is something which can be easily done in a recursion stack. Note that once we get such a value
// we don't need to futher do dfs and we can return from that point
// There are 2 cases where no result is possible
// a) The initial numerator or denominator are not available (check at the very beginning)
// b) The final answer comes out to be the large number we assumed, indicating that no path was found
// In both these cases, return -1

#include <bits/stdc++.h>
using namespace std;

map<string, vector<pair<string, double>>> mp;
vector<string> vis;

double dfs(string a, string b) {
    vis.push_back(a);
    if(mp[a].size() == 0) return 100000.0;
    vector<pair<string, double>> v = mp[a];
    auto it = find_if(v.begin(), v.end(), [&](pair<string, double> p) {
        return p.first == b;
    });
    if(it != v.end()) return it->second;
    double res = 100000.0;
    for(pair<string, double> p : mp[a]) {
        string s = p.first;
		double val = p.second;
        if(find(vis.begin(), vis.end(), s) == vis.end()) {
			double t = dfs(s, b);
			if(t != 100000.0) {
				res = t * val;
				break;
			}
		}
    }

    return res;
}

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    for(int i=0; i<equations.size(); i++) {
        string a = equations[i][0];
        string b = equations[i][1];
        double val = values[i];
        if(mp.find(a) == mp.end()) mp.insert({a, {{b, val}}});
        else mp[a].push_back({b, val});
        if(mp.find(b) == mp.end()) mp.insert({b, {{a, 1/val}}});
        else mp[b].push_back({a, 1/val});
    }

    vector<double> ans;
    for(int i=0; i<queries.size(); i++) {
        vis.clear();
		string s1 = queries[i][0], s2 = queries[i][1];
		if(mp.find(s1) == mp.end() || mp.find(s2) == mp.end()) {
			ans.push_back(-1.00);
			continue;
		}
        double k = dfs(s1, s2);
        ans.push_back(k);
    }

    return ans;
}

int main() {
	vector<vector<string>> eqn = {{"a","b"},{"b","c"},{"bc","cd"}};
	vector<double> val = {1.5,2.5,5.0};
	vector<vector<string>> quer = {{"a","c"},{"c","b"},{"bc","cd"},{"cd","bc"}};
	vector<double> v = calcEquation(eqn, val, quer);
	cout << fixed << setprecision(6);
	for(double d : v)
        cout << d << " ";
}
