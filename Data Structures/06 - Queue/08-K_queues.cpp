#include <bits/stdc++.h>
using namespace std;

class KQueues {
private:
    int *arr;
    int *front;
    int* rear;
    int* next;
    int free;
    int n;
    int k;
public:
    KQueues(int n1, int k1);
    bool isFull();
    void enqueue(int item, int qn);
    int dequeue(int qn);
    bool isEmpty(int qn);
};

KQueues::KQueues(int n1, int k1) {
    n = n1, k = k1;
    arr = new int[n];
    front = new int[k];
    rear = new int[k];
    next = new int[n];

    free = 0;
    for(int i=0; i<k; i++)
        front[i] = -1;
    for(int i=0; i<n; i++)
        next[i] = i+1;
    next[n-1] = -1;
}

bool KQueues::isFull() {
    return (free == -1);
}

void KQueues::enqueue(int item, int qn) {
    if(isFull()) {
        cout << "Stack Overflow\n";
        return;
    }
    int i = free;
    free = next[i];
    if(isEmpty(qn))
        front[qn] = i;
    else
        next[rear[qn]] = i;
    rear[qn] = i;
    next[i] = -1;
    arr[i] = item;
}

int KQueues::dequeue(int qn) {
    if(isEmpty(qn)) {
        cout << "Stack underflow\n";
        return -1;
    }
    int i = front[qn];
    front[qn] = next[i];
    next[i] = free;
    free = i;
    return arr[i];
}

bool KQueues::isEmpty(int qn) {
    return (front[qn] == -1);
}

int main() {
    int k = 3, n = 10;
    KQueues ks(n, k);

    ks.enqueue(15, 2);
    ks.enqueue(45, 2);

    ks.enqueue(17, 1);
    ks.enqueue(49, 1);
    ks.enqueue(39, 1);

    ks.enqueue(11, 0);
    ks.enqueue(9, 0);
    ks.enqueue(7, 0);

    cout << "Dequeued element from queue 2 is " << ks.dequeue(2) << endl;
    cout << "Dequeued element from queue 1 is " << ks.dequeue(1) << endl;
    cout << "Dequeued element from queue 0 is " << ks.dequeue(0) << endl;

    return 0;
}
