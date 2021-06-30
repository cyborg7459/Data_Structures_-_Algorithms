#include <bits/stdc++.h>
using namespace std;

class Heap {
public:
    vector<int> v;
    void print();
    int size();
};

void Heap::print() {
    for(int t : v)
        cout << t << " ";
    cout << endl;
}

int Heap::size() {
    int n = v.size();
    return n;
}

class Max_Heap:public Heap {
public:
    Max_Heap() {};
    Max_Heap(vector<int> _v);
    void insert(int x);
    int delete_root();
};

class Min_Heap:public Heap {
public:
    Min_Heap() {};
    Min_Heap(vector<int> _v);
    void insert(int x);
    int delete_root();
};

void Max_Heap::insert(int x) {
    v.push_back(x);
    int i = v.size() - 1;
    while(i != 0 && x > v[(i-1)/2]) {
        v[i] = v[(i-1)/2];
        v[(i-1)/2] = x;
        i = (i-1)/2;
    }
    v[i] = x;
    return;
}

void Min_Heap::insert(int x) {
    v.push_back(x);
    int i = size()-1;
    while(i != 0 && x < v[(i-1)/2]) {
        v[i] = v[(i-1)/2];
        v[(i-1)/2] = x;
        i = (i-1)/2;
    }
    v[i] = x;
    return;
}

int Max_Heap::delete_root() {
    if(size() == 0) return -1;
    int num = v[0], x = v[size()-1];
    v.pop_back();
    int i = 0;
    v[i] = x;
    while(true) {
        int i1 = 2*i + 1, i2 = 2*i + 2;
        if(i1 >= size()) break;
        else if(i1 == size()-1 && v[i1] > x) {
            v[i] = v[i1];
            v[i1] = x;
            i = i1;
        }
        else {
            int idx;
            if(v[i1] > v[i2]) idx = i1;
            else idx = i2;
            if(x >= v[idx]) break;
            v[i] = v[idx];
            v[idx] = x;
            i = idx;
        }
    }
    v[i] = x;
    return num;
}

int Min_Heap::delete_root() {
    if(size() == 0) return -1;
    int num = v[0], x = v[size()-1];
    v.pop_back();
    int i = 0;
    v[i] = x;
    while(true) {
        int i1 = 2*i + 1, i2 = 2*i + 2;
        if(i1 >= size()) break;
        else if(i1 == size()-1 && v[i1] < x) {
            v[i] = v[i1];
            v[i1] = x;
            i = i1;
        }
        else {
            int idx;
            if(v[i1] < v[i2]) idx = i1;
            else idx = i2;
            if(x <= v[idx]) break;
            v[i] = v[idx];
            v[idx] = x;
            i = idx;
        }
    }
    v[i] = x;
    return num;
}

Max_Heap::Max_Heap(vector<int> _v) {
    for(int t : _v)
        insert(t);
}

Min_Heap::Min_Heap(vector<int> _v) {
    for(int t : _v)
        insert(t);
}

int main() {
	vector<int> v = {4,2,7,1,15,32,14,8,11,17,5};
	Max_Heap maxh(v);
	while(maxh.size()) {
		int t = maxh.delete_root();
		cout << t << " ";
	}
	cout << endl;
	Min_Heap minh(v);
	while(minh.size()) {
	 int t = minh.delete_root();
	 cout << t << " ";
	}
	cout << endl;
}
