#include <bits/stdc++.h>
using namespace std;

class KStacks {
private:
    int n;
    int k;
    int *arr;
    int *top;
    int *next;
    int free;
public:
    KStacks(int _n, int _k);
    bool isFull();
    bool isEmpty(int sn);
    void push(int num, int sn);
    int pop(int sn);
};

KStacks::KStacks(int _n, int _k) {
    n = _n;
    k = _k;
    arr = new int[n];
    top = new int[k];
    next = new int[n];
    free = 0;
    for(int i=0; i<n; i++) next[i] = i+1;
    for(int i=0; i<k; i++) top[i] = -1;
    next[n-1] = -1;
}

bool KStacks::isFull() {
    return (free == -1);
}

bool KStacks::isEmpty(int sn) {
    return (top[sn] == -1);
}

void KStacks::push(int num, int sn) {
    if(isFull()) {
        cout << "Stack Overflow\n";
        return;
    }
    int i = free;
    free = next[i];
    next[i] = top[sn];
    top[sn] = i;
    arr[i] = num;
}

int KStacks::pop(int sn) {
    if(isEmpty(sn)) {
        cout << "Stack empty\n";
        return -1;
    }
    int i = top[sn];
    top[sn] = next[top[sn]];
    next[i] = free;
    free = i;
    return arr[i];
}

int main() {
    KStacks ks(12, 4);
    ks.push(3, 0);
    ks.push(5, 0);
    ks.push(6, 0);
    ks.push(4, 1);
    ks.push(3, 2);
    ks.push(9, 2);
    ks.push(1, 1);
    cout << ks.pop(0) << " ";
    cout << ks.pop(0) << " ";
    cout << ks.pop(0) << endl;
    cout << ks.pop(1) << " ";
    cout << ks.pop(1) << endl;
    cout << ks.pop(2) << " ";
    cout << ks.pop(2) << endl;
}
