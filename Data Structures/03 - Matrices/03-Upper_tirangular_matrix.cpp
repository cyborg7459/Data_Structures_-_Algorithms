#include <bits/stdc++.h>
using namespace std;

class UpperTriangular {
private:
    int n;
    int *A;
public:
    UpperTriangular(int n) {
        this->n = n;
        A = new int[(n*(n+1))/2] {};
    }
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
    void displayArr();
    ~UpperTriangular() {
        delete []A;
        cout << "\nLower triangular matrix was deleted\n";
    }
};

void UpperTriangular::set(int i, int j, int x) {
    if(i<=j) {
        int t = ((i-1)*(2*n-i+2))/2;
        A[(t)+(j-i)] = x;
    }
}

int UpperTriangular::get(int i, int j) {
    if(i<=j) {
        int t = ((i-1)*(2*n-i+2))/2;
        return A[t+j-i];
    }
    return 0;
}

void UpperTriangular::display() {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cout << get(i,j) << " ";
        }
        cout << "\n";
    }
}

void UpperTriangular::displayArr() {
    for(int i=0; i<(n*(n+1))/2; i++) {
        cout << A[i] << " ";
    }
}


int main() {
    UpperTriangular d(5);
    d.set(1,1,5);
    d.set(1,2,5);
    d.set(1,3,5);
    d.set(1,4,5);
    d.set(1,5,5);
    d.set(2,1,5);
    d.set(2,2,5);
    d.set(2,3,5);
    d.set(2,4,5);
    d.set(2,5,5);
    d.set(3,1,5);
    d.set(3,2,5);
    d.set(3,3,5);
    d.set(3,4,5);
    d.set(3,5,5);
    d.set(4,1,5);
    d.set(4,2,5);
    d.set(4,3,5);
    d.set(4,4,5);
    d.set(4,5,5);
    d.set(5,1,5);
    d.set(5,2,5);
    d.set(5,3,5);
    d.set(5,4,5);
    d.set(5,5,5);
    d.display();
}
