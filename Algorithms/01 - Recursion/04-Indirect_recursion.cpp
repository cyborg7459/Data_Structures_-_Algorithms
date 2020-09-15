#include <iostream>
using namespace std;

int x = 0;
int y = 0;

// Function prototype so that funcA knows about this before calling it
void funcB(int n);

void funcA(int n) {
  x++;
  if(n>0) {
    cout << n << " ";
    funcB(n-1);
  }
}

void funcB(int n) {
  y++;
  if(n>1) {
    cout << n << " ";
    funcA(n/2);
  }
}

int main() {
  funcA(50);
  cout << "\nFunction A called " << x << " times\nFunction B called " << y << " times";
  return 0;
}
