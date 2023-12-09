#include <bits/stdc++.h>
using namespace std;
// https://teratail.com/questions/282974
// こいつは要するに内側のloopで少なくとも一回は交換を行ったことを意味する。

// 一度も交換が行われなかったら(flagがfalseなら)交換の必要がなかった、つまりソート完了ってこと。
// 裏返せば、一度でも交換が行われたら(flagがtrueなら)、再度内側のloopを回す必要があるってこと。

//バブルソート
int bubbleSort(int A[], int N) {
  int sw = 0;
  bool flag = 1;
  for(int i = 0; flag; i++) {
    flag = 0;
    for(int j = N - 1; j >= i + 1; j--) {
      if (A[j] < A[j - 1]){
        swap(A[j], A[j-1]);
        flag = 1;
        sw++;
      } 
    }
  }
  return sw;
}

int main() {
  int A[100];
  int N, sw;

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  
  sw = bubbleSort(A, N);
  //出力
  for (int i = 0; i < N; i++) {
    if(i) cout << " ";
    cout << A[i];
  }
  cout << endl;
  cout << sw << endl;

  return 0;
}