#include <iostream>
using namespace std;

double p = 1, f = 1;

double e(int x, int n) {
  double r;
  if(n==0)
    return 1;
  else {
    r = e(x, n-1);
    p = p*x;
    f = f*n;
    return r + p/f;
  }
}

int main()  {
  cout << "Calculation of value of e by Taylor's expansion of :-\n";
  for(int i=1; i<=10; i++) {
    p=1;
    f=1;
    cout << i << " terms : " << e(1,i) << "\n";
  }
}
