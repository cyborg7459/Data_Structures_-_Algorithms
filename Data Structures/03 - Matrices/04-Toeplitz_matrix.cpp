#include <iostream>
using namespace std;

class Toeplitz {
private:
    int n;
    int *A;
public:
    Toeplitz(int n) {
        this->n = n;
        A = new int[2*n-1];
    }
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
    void displayArr();
    ~Toeplitz() {
        cout << "\nDeleting matrix\n";
        delete []A;
    }
};

void Toeplitz::set(int i, int j, int x) {
    if(i==1)
        A[j-1] = x;
    else if(j==1)
        A[n+i-2] = x;
}

int Toeplitz::get(int i, int j) {
    if(j>=i)
        return A[j-i];
    else
        return A[n+(i-j-1)];
}

void Toeplitz::display() {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++)
            cout << get(i,j);
        cout << "\n";
    }
}

void Toeplitz::displayArr() {
    for(int i=0; i<(2*n-1); i++)
        cout << A[i] << " ";
    cout << endl;
}

int main() {
    Toeplitz arr(5);
    arr.set(1,1,1);
    arr.set(1,2,2);
    arr.set(1,3,3);
    arr.set(1,4,4);
    arr.set(1,5,5);
    arr.set(2,1,6);
    arr.set(3,1,7);
    arr.set(4,1,8);
    arr.set(5,1,9);
    arr.display();
}
