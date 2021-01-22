#include <bits/stdc++.h>
using namespace std;

class Heap {
public:
    std::vector<int> v;
    void print();
};

class Max_Heap:public Heap {
public:
    Max_Heap(std::vector<int> arr);
    void insert(int x);
};

class Min_Heap:public Heap {
public:
    Min_Heap(std::vector<int> arr);
    void insert(int x);
};

void Heap::print() {
    int n = v.size();
    for(int i=0; i<n; i++)
        cout << v[i] << " ";
    cout << endl;
}

Max_Heap::Max_Heap(std::vector<int> arr) {
    int n = arr.size();
    v.push_back(arr[0]);
    for(int i=1; i<n; i++)
        v.insert(arr[i]);
}

void Max_Heap::insert(int x) {
    v.push_back(x);
    if(v.size() == 1)
        return;
    else {
        int i = v.size();
        while(i>1 && v[i-1] > v[i/2 - 1]) {
            v[i-1] = v[i/2 - 1];
            i/=2;
        }
        v[i-1] = x;
    }
}

void Min_Heap::insert(int x) {
    v.push_back(x);
    if(v.size() == 1)
        return;
    else {
        int i = v.size();
        while(i>1 && v[i-1] < v[i/2 - 1]) {
            v[i-1] = v[i/2 - 1];
            i/=2;
        }
        v[i-1] = x;
    }
}

int main() {
    Max_Heap maxHeap;
    Min_Heap minHeap;
    maxHeap.insert(10);
    maxHeap.insert(4);
    maxHeap.insert(40);
    maxHeap.print();
    minHeap.insert(10);
    minHeap.insert(4);
    minHeap.insert(40);
    minHeap.print();
}
