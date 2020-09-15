#include <iostream>
using namespace std;

int x = 0;
int y = 0;
int arr[100] = {};


int fib(int n) {
  x++;
  if(n==0)
    return 0;
  if(n==1)
    return 1;
  return fib(n-1)+fib(n-2);
}

int mem_fib(int n) {
  y++;
  if(arr[n]!=-1)
    return arr[n];
  else {
    int t = mem_fib(n-1) + mem_fib(n-2);
    arr[n] = t;
    return t;
  }
}

int main() {
  for(int i=0;i<100;i++)
    arr[i] = -1;
  arr[0] = 0;
  arr[1] = 1;

  for(int i=0; i<=30; i++)
    cout << fib(i) << " ";
  cout << "\nWithout memoization, the total number of function calls required : " << x << "\n\n";

  for(int i=0; i<=30; i++) 
    cout << mem_fib(i) << " ";
  cout << "\nWith memoization, the total number of function calls required : " << y << "\n";

  cout << "\n\nThus, the use of memoization improved the efficiency by " << (x-y) << " units\n\n";
}
