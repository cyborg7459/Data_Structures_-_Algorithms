#include <iostream>
using namespace std;

int t = 0;

int fun(int n) {
  t++;
  int x = 1;
  int k;
  if(n==1)
    return x;
  for(k=1; k <n; k++)
    x = x+(fun(k)*fun(n-k));
  return x;
}

int main() {
  cout << fun(5);
  cout << t;
}
