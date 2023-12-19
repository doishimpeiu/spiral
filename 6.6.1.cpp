#include <bits/stdc++.h>
using namespace std;

int functional(int n){
  if (n == 1) return 1;
  return n * functional(n - 1);
}

int main(){
  int n = 5;
  n = functional(n);
  cout << n << endl;

  return 0;
}