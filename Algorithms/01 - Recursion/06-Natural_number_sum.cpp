#include <iostream>
using namespace std;

int x = 0;

int sum_of_N(int n) {
  x++;
  if(n==1) {
    return 1;
  }
  else {
    return sum_of_N(n-1) + n;
  }
}

int main() {
  for(int i=1; i<=20; i++) {
    x=0;
    cout << "Sum of first " << i << " natural numbers : " << sum_of_N(i);
    cout << "\nThe function was called " << x << " times\n\n\n";
  }
}
