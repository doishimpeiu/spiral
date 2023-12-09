#include <bits/stdc++.h>
using namespace std;

int selectionSort(int A[], int N) {
  int sw = 0;
  for(int i = 0; i < N - 1; i++) {
    int minj = i;
    for(int j = i; j < N; j++) {
      if(A[j] < A[minj]) minj = j;
    }
    swap(A[i], A[minj]);
    if(i != minj) sw++;
  }
  return sw;
}

int main() {
  int A[100], N;

  //入力
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  int sw = selectionSort(A, N);

  //出力
  for (int i = 0; i < N; i++) {
    if(i) cout << " ";
    cout << A[i];
  }
  cout << endl;
  cout << sw << endl;

  return 0;
}