#include <iostream>
using namespace std;

int x = 0;

void TOH(int n,char a, char b, char c) {
  x++;
  if(n==1) {
    cout << "Move disk from position " << a << " to position " << c << "\n";
  }
  else {
    TOH(n-1,a,c,b);
    cout << "Move disk from position " << a << " to position " << c << "\n";
    TOH(n-1,b,a,c);
  }
}

int main() {
  TOH(3,'A','B','C');
  cout << "\nNumber of steps required : " << x << "\n";
}
