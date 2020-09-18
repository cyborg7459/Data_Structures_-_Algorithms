#include <iostream>
using namespace std;

struct Array {
  int A[20];
  int size;
  int length;
};

void fill(struct Array &x) {
    for(int i=0; i<x.length; i++) {
        int t;
        cin >> t;
        x.A[i] = t;
    }
}

void display(struct Array x) {
    for(int i=0; i<x.length; i++) {
        cout << x.A[i] << " ";
    }
    cout << endl;
    return;
}

void append(struct Array &x, int t) {
    if(x.length == x.size)
        cout << "Can't append, maximum limit reached";
    else {
        x.A[x.length] = t;
        x.length++;
        // display(x);
    }
}

void insert(struct Array &x, int el, int t) {
    if(x.length == x.size)
        cout << "Array has reached size limit. No more elements can be added\n";
    else if(t>x.length)
        cout << "Index does not lie in the array range\n";
    else {
        for(int i=x.length-1; i>=t;i--)
            x.A[i+1] = x.A[i];
        x.A[t] = el;
        x.length++;
        display(x);
    }
}

void delete_elem(struct Array &x, int t) {
    if(t>=x.length)
        cout << "Index lies beyond length of array\n";
    else {
        for(int i=t; i<x.length; i++)
            x.A[i] = x.A[i+1];
        x.length--;
        display(x);
    }
}

int search(struct Array x, int t)  {
    for(int i=0; i<x.length; i++) {
        if(x.A[i] == t)
            return i;
    }
    return -1;
}

int get(struct Array x, int i) {
    if(i >= x.length) {
        cout << "The index does not exist in the array\n";
        return -1;
    }
    else {
        return x.A[i];
    }
}

void set(struct Array &x, int t, int i) {
    if(i >= x.length)
        cout << "The index does not exist in the array\n";
    else
        x.A[i] = t;
    display(x);
}

int max(struct Array x) {
    int t = x.A[0];
    for(int i=0; i<x.length; i++) {
        if(x.A[i] > t)
            t = x.A[i];
    }
    return t;
}

int min(struct Array x) {
    int t = x.A[0];
    for(int i=0; i<x.length; i++) {
        if(x.A[i] < t)
            t = x.A[i];
    }
    return t;
}

int sum(struct Array x) {
    int t = 0;
    for(int i=0; i<x.length; i++) {
        t += x.A[i];
    }
    return t;
}

double avg(struct Array x) {
    return (double)sum(x)/x.length;
}

void reverse(struct Array &x) {
    int i = 0;
    int j = x.length-1;
    while(i<j) {
        swap(x.A[i], x.A[j]);
        i++;
        j--;
    }
    display(x);
}

void rotate_left(struct Array &x, int t) {
    t = t%x.length;
    struct Array y = {{}, 10, 0};
    for(int i=t; i<x.length; i++) {
        append(y, x.A[i]);
    }
    for(int i=0; i<t; i++) {
        append(y, x.A[i]);
    }
    x = y;
    display(x);
}

void rotate_right(struct Array &x, int t) {
    t = t%x.length;
    struct Array y = {{}, 10, 0};
    for(int i=x.length-1; i>(x.length-1-t); i--) {
        append(y, x.A[i]);
    }
    for(int i=0; i<x.length-t; i++) {
        append(y, x.A[i]);
    }
    x = y;
    display(x);
}

int main() {
    struct Array arr = {{2,3,4,5,6}, 10,5};
    return 0;
}
