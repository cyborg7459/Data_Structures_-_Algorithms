// PS : Given a circular path with several petrol stations in between. For each petrol station, we know the amount of petrol available, and the distance from the next petrol station.
// We have to find out index of such a petrol pump such that if we start from there, we can cover the complete circle without out petrol finishing. (assuming 1 unit distance per 1 unit petrol mileage)

#include <bits/stdc++.h>
using namespace std;

struct petrolPump {
	int petrol;
	int distance;
};

int tour(petrolPump p[], int n)
{
	int add_val = 0, start = 0, prefix_sum = 0;
	for(int i=0; i<n; i++) {
		prefix_sum += p[i].petrol - p[i].distance;
		if(prefix_sum + add_val < 0) {
			add_val += -1 * (prefix_sum + add_val);
			start = i+1;
		}
	}

	if(start >= n) return -1;

	int i = start+1, sum = p[start].petrol - p[start].distance;
	if(i == n) i = 0;
	while(i != start) {
		sum += p[i].petrol - p[i].distance;
		if(sum < 0) return -1;
		i++;
		if(i == n) i = 0;
	}

	return start;
}

int main() {
	int n;
	cin >> n;
	petrolPump p[n];
	for(int i=0; i<n; i++) {
		int a, b;
		cin >> a >> b;
		struct petrolPump x;
		x.petrol = a;
		x.distance = b;
		p[i] = x;
	}
	cout << tour(p, n) << endl;
}
