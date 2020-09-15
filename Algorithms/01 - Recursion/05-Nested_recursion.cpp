#include <iostream>
using namespace std;

int x = 0;

int func(int n) {
  x++;
  if(n>100) {
    return n-10;
  }
  else {
      func(func(n+11));
  }
}

int main() {
  for(int i=90; i<=110; i++) {
    x=0;
    cout << func(i);
    cout << "\nThe function was called " << x << " times for n = " << i << "\n\n\n";
  }
  return 0;
}
