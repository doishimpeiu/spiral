#include <bits/stdc++.h>
using namespace std;
int MAX = 10000;

int linearSearch(int A[], int n, int key){
  int i = 0;  //iは配列の何番目にいるのかを表す
  A[n] = key;  //配列の最後尾に番兵を入れる
  while(A[i] != key) i++;  //配列の値とkeyが一致するまでi(配列の何番目か)を加算する
  return i != n;  //iとnが一致していなければ1を返し, 一致していれば(番兵であれば)0を返す
}

int main() {
  int n, q, key;
  int sum = 0;
  cin >> n;
  int S[MAX];
  for (int i = 0; i < n; i++) {
    cin >> S[i];
  }
  cin >> q;
  int T[MAX];
  for (int i = 0; i < q; i++){
    cin >> T[i];
  }

  for(int i = 0; i < q; i++){
    key = T[i];
    if(linearSearch(S, n, key)) sum++;
  }

  cout << sum << endl;

  return 0;
}