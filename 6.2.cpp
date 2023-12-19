#include <bits/stdc++.h>
using namespace std;

//n:数列の個数, A:数列を入れる配列
int n, A[50];

//入力値のMから選んだ要素を引いていく再帰関数
//i番目以降の要素を使ってmを作れる場合true
int solve(int i, int m){
  if(m == 0) return 1;
  if(i >= n) return 0;
  // (配列A[i]を使わずに次の配列に進む) || (配列A[i]を引いて次の配列に進む b)
  int res = solve(i + 1, m) || solve(i + 1, m - A[i]);
  return res;
}

int main() {
  //q:質問の個数, M:i番目の質問, i:カウンタ
  int q, M, i;

  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", &A[i]);
  scanf("%d", &q);
  for(int i = 0; i < q; i++) {
    scanf("%d", &M);
    if(solve(0, M)) printf("yes\n");
    else printf("no\n");
  }

  return 0;
}