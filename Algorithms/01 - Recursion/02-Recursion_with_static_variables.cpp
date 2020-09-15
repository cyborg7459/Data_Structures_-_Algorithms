#include <iostream>
using namespace std;

int t = 10;

int func(int n) {
  if(n>0) {
    return func(n-1) + n;
  }
  return 0;
}

int static_func(int n) {
  static int x=0;
  if(n>0) {
    x++;
    return static_func(n-1) + x;
  }
  return 0;
}

int global_func(int n) {
  if(n>0) {
    return global_func(n-1) + t;
  }
  return 0;
}

int main() {
  cout << func(5) << "\n" << static_func(5) << "\n" << global_func(5) << endl;
  return 0;
}
