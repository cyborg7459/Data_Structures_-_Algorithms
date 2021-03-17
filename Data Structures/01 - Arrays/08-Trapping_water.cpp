// PROBLEM : https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1/?track=md-arrays&batchId=144
// EXPLANATION : First step is to calculate the maximum height column in the entire array and store it's index. Now we maintain 2 separate vectors, one for the left side of max and one for the right
// side of max. In both vectors, we start from one end and move towards the max column, and in the path, whichever columns are taller or equal to all columns encountered up till now, we'll store their
// height and the index. The reason to do this is that we can now simply keep calculating the water that is stored between them 2 and subtract the space taken by any smaller columns that occur in
// between. This gives the desired result.


#include <bits/stdc++.h>
using namespace std;


int trappingWater(int arr[], int n){
	vector <pair<int, int>> v1, v2;
	int max = -1, maxi = -1;
	for(int i=0; i<n; i++) {
	    if(arr[i] >= max) {
		max = arr[i];
		maxi = i;
	    }
	}
	int temp = -1;
	for(int i=0; i<maxi; i++) {
	    if(arr[i] >= temp) {
			temp = arr[i];
			v1.push_back({i, temp});
	    }
	}
	int res = 0;
	for(int i=0; i<v1.size(); i++) {
	    if(i != v1.size()-1) {
			res+= (v1[i+1].first - v1[i].first - 1) * v1[i].second;
			for(int j = v1[i].first + 1; j< v1[i+1].first; j++)
				res -= arr[j];
	    }
	    else {
			res+= (maxi - v1[i].first - 1)*v1[i].second;
			for(int j = v1[i].first + 1; j<maxi; j++)
				res -= arr[j];
	    }
	}
	temp = -1;
	for(int i=n-1; i>maxi; i--) {
		if(arr[i] >= temp) {
			temp = arr[i];
			v2.push_back({i, temp});
		}
	}
	for(int i=0; i<v2.size(); i++) {
		if(i!=v2.size()-1) {
			res += (v2[i].first - v2[i+1].first - 1) * v2[i].second;
			for(int j = v2[i+1].first + 1; j < v2[i].first; j++) {
				res -= arr[j];
			}
		}
		else {
			res += (v2[i].first - maxi - 1) * v2[i].second;
			for(int j = maxi+1; j<v2[i].first; j++)
				res-=arr[j];
		}
	}
	return res;
}

int main() {
    int arr[10] = {1,5,0,0,6,4,0,0,5,1};
	cout << trappingWater(arr, 10);
}
