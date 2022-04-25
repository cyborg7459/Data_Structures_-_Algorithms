// PS : In this problem, we have to arrange the elements of an array in such a way that the positive and negative elements become alternate (as long as there are remaining pos and neg). There are
// 2 conditions :-
// 1) Relative order of the positive and negative elements must remain same
// 2) O(1) space complexity

// Solution : The 2 conditions make this otherwise extremely simple question into a challenging one. In the given solution, we're keeping positive numbers at odd indexes and vice versa. Now we traverse
// the entire array, while keeping in mind the next index where a positive integer should go (pi). As soon as we reach a positive number, we check it's position w.r.t pi. If both are same then the
// element is in the correct position. The way we are solving this question ensures that the left part of the current pi value is correctly arranged, hence we don't need to worry about that. If pi < i, it
// means that all elements b/w pi and i are negative, else we would've got the positive integer already. Now we reverse all the elements from pi to i, thus the number at i goes to pi, which is required. Now
// we again reverse from pi+1 to i. This ensures that the relative order of the remaining elements did not change. It also made sure that the pi+1 has a negative integer, hence maintaining the alternation.
// If pi > i, then by the manner we have solved the given question, pi would definitely be i+1. In this case, all we have to do is find the next negative index ni and then reverse from i to ni, thus putting
// a negative integer at i, and then reversing i+1 to i hence maintaining order as well as alteration. Be careful with the updation statements for i and pi though.

#include <bits/stdc++.h>
using namespace std;

#define print(x) {for(auto t : x)\
				cout << t << " ";\
				cout << "\n";}
#define INF 1000000007

void rev(vector<int> &v, int a, int b) {
	while(a < b) {
		v[a] += v[b];
		v[b] = v[a] - v[b];
		v[a] -= v[b];
		a++;
		b--;
	}
}

int main() {
	vector<int> v = {1,2,3,4,5,-4,-1,-2,-3};
	int n = v.size();
	int p_i = 0, cur_i = 0;
	while(cur_i < n) {
		if(v[cur_i] >= 0) {
			if(p_i == cur_i) {
				p_i+=2;
				cur_i++;
			}
			else if(p_i < cur_i) {
				rev(v, p_i, cur_i);
				rev(v, p_i+1, cur_i);
				p_i += 2;
				cur_i++;
			}
			else {
				int next_neg = cur_i;
				while(next_neg < n && v[next_neg] >=0)
					next_neg++;
				if(next_neg >= n) break;
				else {
					rev(v, cur_i, next_neg);
					rev(v, cur_i+1, next_neg);
					cur_i++;
          p_i+=2;
				}
			}
		}
		else cur_i++;
	}
	print(v);
}
