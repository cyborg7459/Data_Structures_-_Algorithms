// PS : Difference of this problem from normal DP is that here we can break the item, i.e. if adding an item makes the weight go beyond capacity, we can break the item and add it. The value also changes
// in proportion with the weight
// Explanation : Since in the given problem, we'll completely fill the Knapsack in all cases, hence there is no need for DP. We just need to chooose the most favourable weight at each step. Which
// would be the one with the highest value/weight ratio

#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

class Solution {
public:
    double fractionalKnapsack(int W, Item arr[], int n) {
        sort(arr, arr+n, [](Item a, Item b) {
            return (double)a.value/a.weight > (double)b.value/b.weight;
        });
        double cur = 0.0, ans = 0.0;
        int idx = 0;
        while(idx < n) {
            if(cur + arr[idx].weight < W) {
                cur += arr[idx].weight;
                ans += arr[idx].value;
                idx++;
            }
            else {
                double diff = W - cur;
                double x = ((double)arr[idx].value/(double)arr[idx].weight) * diff;
                ans += x;
                break;
            }
        }
        return ans;
    }
};

int main()
{
	int t;
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
		int n, W;
		cin>>n>>W;
		Item arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n);
	}
    return 0;
}
