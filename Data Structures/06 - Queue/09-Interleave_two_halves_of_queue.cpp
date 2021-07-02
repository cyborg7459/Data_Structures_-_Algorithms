#include <bits/stdc++.h>
using namespace std;

void display(queue<int> q) {
	while(!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << "\n";
}

int main() {
	int n = 9;
	queue<int> q;
	q.push(11);
	q.push(12);
	q.push(13);
	q.push(14);
	q.push(15);
	q.push(16);
	q.push(17);
	q.push(18);
	q.push(19);
	stack<int> s1, s2;
	bool b = true;
	for(int i=0; i<ceil((double)n/2); i++) {
		s1.push(q.front());
		q.pop();
	}
	for(int i=ceil((double)n/2); i<n; i++) {
		s2.push(q.front());
		q.pop();
	}
	b = true;
	while(true) {
		if(b) {
			if(s1.empty()) break;
			else {
				q.push(s1.top());
				s1.pop();
			}
		}
		else {
			if(s2.empty()) break;
			else {
				q.push(s2.top());
				s2.pop();
			}
		}
		b = !b;
	}

	stack<int> s;
	while(!q.empty()) {
		s.push(q.front());
		q.pop();
	}
	while(!s.empty()) {
		q.push(s.top());
		s.pop();
	}

	display(q);
}
