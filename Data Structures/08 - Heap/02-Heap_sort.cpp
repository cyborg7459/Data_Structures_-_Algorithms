#include <bits/stdc++.h>
using namespace std;

class Heap {
public:
    std::vector<int> v;
    Heap(std::vector<int> arr);
    void insert(int x);
    int delete_root();
};

Heap::Heap(std::vector<int> arr) {
    int n = arr.size();
    for(int i=0; i<n; i++)
        insert(arr[i]);
}

void Heap::insert(int x) {
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

int Heap::delete_root() {
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

void HeapSort(std::vector<int> &v) {
    Heap mh(v);
    int n = v.size();
    for(int i=0; i<n; i++)
        v[i] = mh.delete_root();
}

int main() {
    std::vector<int> v = {40,35,30,15,10,25,5};
    HeapSort(v);
    for(int i=0; i<v.size(); i++)
        cout << v[i] << " ";
}
