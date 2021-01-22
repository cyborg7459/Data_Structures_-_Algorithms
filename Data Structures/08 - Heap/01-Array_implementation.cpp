#include <bits/stdc++.h>
using namespace std;

class Heap {
public:
    std::vector<int> v;
    void print();
    int size();
};

void Heap::print() {
    int n = v.size();
    for(int i=0; i<n; i++)
    cout << v[i] << " ";
    cout << endl;
}

int Heap::size() {
    return v.size();
}

class Max_Heap:public Heap {
public:
    Max_Heap() {};
    Max_Heap(std::vector<int> arr);
    void insert(int x);
    int delete_root();
};

class Min_Heap:public Heap {
public:
    Min_Heap() {};
    Min_Heap(std::vector<int> arr);
    void insert(int x);
    int delete_root();
};

Max_Heap::Max_Heap(std::vector<int> arr) {
    int n = arr.size();
    for(int i=0; i<n; i++)
        insert(arr[i]);
}

Min_Heap::Min_Heap(std::vector<int> arr) {
    int n = arr.size();
    for(int i=0; i<n; i++)
        insert(arr[i]);
}

void Max_Heap::insert(int x) {
    v.push_back(x);
    if(v.size() == 1)
        return;
    else {
        int i = v.size();
        while(i>1 && v[i-1] > v[i/2 - 1]) {
            v[i-1] = v[i/2 - 1];
            v[i/2 - 1] = x;
            i/=2;
        }
        v[i-1] = x;
    }
}

int Max_Heap::delete_root() {
    if(v.size() == 0)
        return -1;
    int deleted = v[0], num = v[v.size()-1];
    int sz = v.size();
    v.pop_back();
    v[0] = num;
    int i = 1;
    while(true) {
        int lchild = 2*i;
        int maxi = lchild;
        if(lchild > sz)
            break;
        int rchild = 2*i + 1;
        if(rchild <= sz && v[rchild-1]>v[lchild-1])
            maxi = rchild;
        if(v[maxi-1] > num) {
            v[i-1] = v[maxi-1];
            v[maxi-1] = num;
            i = maxi;
        }
        else
            break;
    }
    return deleted;
}

void Min_Heap::insert(int x) {
    v.push_back(x);
    if(v.size() == 1)
        return;
    else {
        int i = v.size();
        while(i>1 && v[i-1] < v[i/2 - 1]) {
            v[i-1] = v[i/2 - 1];
            v[i/2 - 1] = x;
            i/=2;
        }
        v[i-1] = x;
    }
}

int Min_Heap::delete_root() {
    if(v.size() == 0)
    return -1;
    int deleted = v[0], num = v[v.size()-1];
    int sz = v.size();
    v.pop_back();
    v[0] = num;
    int i = 1;
    while(true) {
        int lchild = 2*i;
        int maxi = lchild;
        if(lchild > sz)
        break;
        int rchild = 2*i + 1;
        if(rchild <= sz && v[rchild-1]<v[lchild-1])
        maxi = rchild;
        if(v[maxi-1] < num) {
            v[i-1] = v[maxi-1];
            v[maxi-1] = num;
            i = maxi;
        }
        else
            break;
    }
    return deleted;
}

int main() {
    Max_Heap maxHeap({5,25,10,15,30,35,40});
    Min_Heap minHeap({40,35,30,15,10,25,5});
    maxHeap.print();
    while(maxHeap.size() > 0) {
        maxHeap.delete_root();
        maxHeap.print();
    }
    minHeap.print();
    while(minHeap.size() > 0) {
        minHeap.delete_root();
        minHeap.print();
    }
}
