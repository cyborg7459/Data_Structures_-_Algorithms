#include <bits/stdc++.h>
using namespace std;

class Diagonal {
private:
    int n;
    int *A;
public:
    Diagonal(int n) {
        this->n = n;
        A = new int[n] {};
    }
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
    ~Diagonal() {
        delete []A;
        cout << "\nDiagonal matrix was deleted\n";
    }
};

void Diagonal::set(int i, int j, int x) {
    if(i==j)
        A[i-1]=x;
}

int Diagonal::get(int i, int j) {
    if(i==j)
        return A[i-1];
    return 0;
}

void Diagonal::display() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i==j)
                cout << A[i] << " ";
            else
                cout << "0 ";
        }
        cout << "\n";
    }
}


int main() {
    Diagonal d(5);
    d.set(1,1,5);
    d.set(3,3,3);
    d.display();
}
