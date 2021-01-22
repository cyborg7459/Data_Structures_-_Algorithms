#include <bits/stdc++.h>
using namespace std;

class Max_Heap {
private:
    std::vector<int> v;
public:
    void insert(int x);
    void print();
};

void Max_Heap::print() {
    int n = v.size();
    for(int i=0; i<n; i++)
        cout << v[i] << " ";
    cout << endl;
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
    print();
}

int main() {
    Max_Heap heap;
    heap.insert(10);
    heap.insert(4);
    heap.insert(40);
    heap.print();
}
