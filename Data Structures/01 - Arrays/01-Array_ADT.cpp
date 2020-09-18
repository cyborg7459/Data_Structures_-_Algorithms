#include <iostream>
using namespace std;

struct Array {
  int* A;
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
        display(x);
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

int main() {
    struct Array arr;
    int n,m;

    while(true) {
        cout << "Enter length of array : ";
        cin >> n;
        cout << "Enter maximum size of the array : ";
        cin >> m;
        if(m<n)
            cout << "Array length cannot exceed the maximum size\n";
        else if(n<0 || m<0)
            cout << "Negative values are not accepted\n";
        else
            break;
   }

    arr.length = n;
    arr.size = m;
    int *x = new int[100];
    arr.A = x;

    cout << "Enter elements of the array : ";
    fill(arr);
    display(arr);

    cout << max(arr) << "\n" << min(arr) << "\n" << sum(arr) << "\n" << avg(arr) << "\n";

    // int el, idx;
    // cout << "Enter element to add : ";
    // cin >> el;
    // cout << "Enter index : ";
    // cin >> idx;
    // insert(arr, el, idx);
    //
    // int app;
    // cout << "Enter element to append : ";
    // cin >> app;
    // append(arr, app);
    //
    // int del;
    // cout << "Enter element to delete : ";
    // cin >> del;
    // delete_elem(arr, del);
    //
    // int src;
    // cout << "Enter element to search : ";
    // cin >> src;
    // cout << "Element found at index : " << search(arr, src) << "\n";

    return 0;
}
