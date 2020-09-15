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

int fast_power(int n, int pow) {
  x++;
  if(pow==0)
    return 1;
  if(pow%2==0)
    return fast_power(n*n, pow/2);
  else
    return fast_power(n*n,(pow-1)/2) * n;
}

int main() {
  cout <<  power(2,9) << "\n";
  cout << "The function was called " << x << " times\n";
  x=0;
  fast_power(2,9);
  cout << "By faster method, function was called " << x << " times\n";
}
