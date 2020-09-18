#include <iostream>
using namespace std;

int N = 0;
int arr[100][100] = {};

bool is_attacked(int x,int y) {
  for(int i=0; i<N; i++) {
    if(arr[i][y]==1 || arr[x][i]==1) return true;
  }
  for(int i=0;i<N;i++) {
    for(int j=0; j<N; j++) {
      if(arr[i][j]==1 && ((i+j==x+y)||(i-j==x-y))) return true;
    }
  }
  return false;
}

bool N_queen(int N) {
  if(N==0) return true;
  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) {
      if(!is_attacked(i,j))
        arr[i][j] = 1;
      else {
        arr[i][j]=0;
        continue;
      }
      if(N_queen(N-1)) return true;
    }
  }
  return false;
}

void printBoard() {
  for(int i=0;i<N;i++) {
    for(int j=0; j<N; j++) {
      cout << arr[i][j] << " ";
    }
    cout << "\n";
  }
}

int main() {
  cin >> N;
  if(N_queen(N)) {
    cout << "YES\n";
  }
  else {
    cout << "NO\n";
  }
  printBoard();
}
