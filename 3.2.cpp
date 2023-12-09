#include <bits/stdc++.h>
using namespace std;

//配列の要素を順番に出力
void trace(int A[], int N) {
  //出力
  for (int i = 0; i < N; i++) {
    if(i) cout << " ";
    cout << A[i];
  }
  cout << endl;
}

//挿入ソートで昇順に並べる
void insertionSort(int A[], int N) {  //N個の要素を含む0-オリジンの配列A
  int v, j;
  for (int i = 1; i <= N - 1; i++) {  //1個目と比較するのは2個目からなのでi = 1から始まる
    v = A[i];  //vに2番目の値を代入(比較対象)
    j = i - 1;  //jはv(比較対象)よりも前のインデックス
    while(j >= 0 && A[j] > v) {  //jが0よりも大きい and v(比較対象)よりも大きい値が前にある 時
      A[j+1] = A[j];  //1番目と2番目を入れ替える
      j--;
    }
    A[j + 1] = v;  //最後に空いた位置にvを挿入する
    trace(A, N);
  }
}

int main() {
  int A[100], N;
  
  //入力
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  trace(A, N);
  insertionSort(A, N);

  return 0;
}