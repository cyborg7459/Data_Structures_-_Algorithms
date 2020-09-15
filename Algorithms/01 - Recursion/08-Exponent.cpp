#include <iostream>
using namespace std;

int x=0;

int power(int n, int pow) {
  x++;
  if(pow==1) {
    return n;
  }
  else {
    return power(n,pow-1) * n;
  }
}

int main() {
  cout << x << "  " <<  power(2,5) << "   " << x << "\n";
  cout << "The function was called " << x << " times\n";
}
