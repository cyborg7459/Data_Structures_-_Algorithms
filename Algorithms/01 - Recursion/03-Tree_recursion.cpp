#include <iostream>
using namespace std;

int x = 0;

void func(int n) {
  x++;
  if(n>0) {
    cout << n << " ";
    func(n-1);
    func(n-1);
  }
}

int main() {
  for(int i=1;i<=10;i++) {
    x=0;
    func(i);
    cout << "\nNumber of recursive calls for n = " << i << " is : " << x << "\n\n\n";
  }
  return 0;
}
