#include <iostream>
using namespace std;

void func(int n) {
  if(n>0) {
    cout << n << " ";
    func(n-1);
  }
}

void func1(int n) {
  if(n>0) {
    func1(n-1);
    cout << n << " ";
  }
}

int main() {
  func(10);
  cout << "\n";
  func1(10);
  return 0;
}
