// PS : Given a set of N jobs where each job i has a deadline and profit associated to it. Each job takes 1 unit of time to complete and only one job can be scheduled at a time.
// We earn the profit if and only if the job is completed by its deadline. The task is to find the maximum profit and the number of jobs done.

// Explanation : We'll solve this by greedy apporach. There are 2 possible routes:-
// 1) We do the tasks which have the earliest deadline first, and for the same deadline we do the task offering the maximum profit. However this doesn't give optimal result
//    Counterexample : (1, 20), (1, 30), (2, 40), (2, 50) => Here it is optimal to perform the last 2 jobs in the first 2 seconds
// 2) We do the task which gives the maximum profit first, irrespective of the deadline. This again, is not optimal
//    Counterexample : (4,100), (1,30), (1,40), (1,50) => We couldn've done 4th task in the first second and then the first task, earning a total of 150 profit
// The most optimal way, hence, is that we do the tasks giving the maximum profit, but do them as late as possible, thus freeing up earlier time slots for some less proftable tasks with shorter
// deadlines. Thus, we'll sort in descending order by profit. And then whichever is the last time slot available before it's deadline (we find this using the upper_bound function), do the task at
// that time. If no time slot is available before deadline (i.e. upper_bound is the first element), then obviously we cannot do that task

#include<bits/stdc++.h>
using namespace std;

struct Job {
    int id;
    int dead;
    int profit;
};

class Solution
{
public:
    vector<int> JobScheduling(Job arr[], int n) {
        vector<int> v;
        for(int i=1; i<=100; i++)
            v.push_back(i);
        sort(arr, arr+n, [](Job a, Job b) {
            if(a.profit == b.profit)
                return a.dead < b.dead;
            return a.profit > b.profit;
        });
        int cnt = 0, sum = 0;
        for(int i=0; i<n; i++) {
            Job j = arr[i];
            auto it = upper_bound(v.begin(), v.end(), j.dead);
            if(it == v.begin()) continue;
            it--;
            v.erase(it);
            cnt++;
            sum += j.profit;
        }
        return vector<int>{cnt,sum};
    }
};

int main() {
    int n;
    cin >> n;
    Job arr[n];
    for(int i = 0;i<n;i++){
            int x, y, z;
            cin >> x >> y >> z;
            arr[i].id = x;
            arr[i].dead = y;
            arr[i].profit = z;
    }
    Solution ob;
    vector<int> ans = ob.JobScheduling(arr, n);
    cout<<ans[0] << " " << ans[1];
	return 0;
}
