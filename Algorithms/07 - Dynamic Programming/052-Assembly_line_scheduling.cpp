// PS : There is an assembly line with 2 conveyor belts. We know the time taken for entering and exiting both conveyor belts, along with the time taken by each process on both the belts. Also, we
// can switch between 2 conveyor belts, but that takes some time as well. Find the minimum cost to complete all the processes and exit
// Explanation : We keep 2 arrays t1 and t2 where t1[i] represents minimum time to come out of ith process on first belt, and vice versa. Base cases t1[0] and t2[0] are obvious. The transition statement
// is as follows. For a process on a belt, there are 2 options, either we come from the previous process on the same belt, complete the process and proceed, or we come from the other belt with some cost,
// and then complete the process. We'll choose the minimum out of these 2 values to get optimal array. At the end, we also need to add the exit times 

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 4;
    int process_time[2][n] = {
        {4, 5, 3, 2},
        {2, 10, 1, 4}
    };
    int transfer_time[2][n] = {
        {0, 7, 4, 5},
        {0, 9, 2, 8}
    };
    int entry_time[2] = {10, 12};
    int exit_time[2] = {18, 7};

    int t1[n];
    int t2[n];

    t1[0] = entry_time[0] + process_time[0][0];
    t2[0] = entry_time[1] + process_time[1][0];

    for(int i=1; i<n; i++) {
        t1[i] = process_time[0][i] + min(t1[i-1], t2[i-1] + transfer_time[1][i]);
        t2[i] = process_time[1][i] + min(t1[i-1] + transfer_time[0][i], t2[i-1]);
    }

    cout << min(t1[n-1] + exit_time[0], t2[n-1] + exit_time[1]);
}
