#include <bits/stdc++.h>
using namespace std;

class LowerTriangular {
private:
    int n;
    int *A;
public:
    LowerTriangular(int n) {
        this->n = n;
        A = new int[(n*(n+1))/2] {};
    }
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
    ~LowerTriangular() {
        delete []A;
        cout << "\nLower triangular matrix was deleted\n";
    }
};

void LowerTriangular::set(int i, int j, int x) {
    if(i>=j) {
        int t = ((i-1)*i)/2;
        A[(t)+(j-1)] = x;
    }
}

int LowerTriangular::get(int i, int j) {
    if(i>=j) {
        int t = ((i-1)*i)/2;
        return A[t+j-1];
    }
    return 0;
}

void LowerTriangular::display() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i>=j) {
                int t = ((i+1)*i)/2;
                cout << A[t+j] << " ";
            }
            else
                cout << "0 ";
        }
        cout << "\n";
    }
}


int main() {
    LowerTriangular d(5);
    d.set(1,1,5);
    d.set(3,3,3);
    d.set(1,4,9);
    d.display();
}
