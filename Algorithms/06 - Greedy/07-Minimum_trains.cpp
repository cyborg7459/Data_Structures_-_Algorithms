// PS : Given the arrival and departure time of 'n' trains, caluclate the number of platforms needed to accomodate all the trains
// Explanation : Use the the approach where we need to find the count of an event at a particular time when we know for each event as to when the event starts and when it ends
// Thus, we'll sort both the arrival and departure arrays and then caluclate the number of trains currently in the station at all times. The maximum number of trains at one time
// gives the required answer

#include <bits/stdc++.h>
using namespace std;

int findPlatform(int arr[], int dep[], int n) {
	sort(arr, arr+n);
	sort(dep, dep+n);
	int i1 = 0, i2 = 0;
	int cur = 0, ans = 0;
	while(i1 < n && i2 < n) {
	    if(arr[i1] <= dep[i2]) {
	        cur++;
	        i1++;
	    }
	    else {
	        cur--;
	        i2++;
	    }
	    ans = max(ans, cur);
	}
	return ans;
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    int dep[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int j=0;j<n;j++){
        cin>>dep[j];
    }
    cout << findPlatform(arr, dep, n);
    return 0;
}
