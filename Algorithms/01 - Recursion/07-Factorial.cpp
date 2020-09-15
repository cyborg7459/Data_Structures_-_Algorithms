#include <iostream>
using namespace std;

int x = 0;

int fact(int n) {
  x++;
  if(n==0) {
    return 1;
  }
  else {
    return fact(n-1) * n;
  }
}

int main() {
  for(int i=0; i<=10; i++) {
    x=0;
    cout << "Factorial of " << i << " is : " <<  fact(i);
    cout << "\nThe function was called " << x << " times\n\n\n";
  }
}
