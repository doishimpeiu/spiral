#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

//n:数列の個数, A:数列を入れる配列
int n, A[50];
int dp[50][50];

//入力値のMから選んだ要素を引いていく再帰関数
//i番目以降の要素を使ってmを作れる場合true
int solve(int i, int m){
  // cout << "solve" << endl;
  //if dp[i][m]が計算ずみ
  if (dp[i][m] != 0){
    // cout << "dp[" << i << "][" << m << "]" << endl;
    return dp[i][m];
  }

  if (m == 0) {
    // cout << "true1" << endl;
    // cout << "dp[" << i << "][" << m << "]" << endl;
    dp[i][m] = true;
  } else if (i >= n) {
    // cout << "false1" << endl;
    // cout << "dp[" << i << "][" << m << "]" << endl;
    dp[i][m] = false;
  } else if(solve(i + 1, m)) {
    // cout << "true2" << endl;
    // cout << "dp[" << i << "][" << m << "]" << endl;
    dp[i][m] = true;
  } else if(solve(i + 1, m - A[i])) {
    // cout << "true3" << endl;
    // cout << "dp[" << i << "][" << m << "]" << endl;
    dp[i][m] = true;
  } else {
    // cout << "true2" << endl;
    // cout << "dp[" << i << "][" << m << "]" << endl;
    dp[i][m] = false;
  }

  return dp[i][m];
}

int main() {
  //q:質問の個数, M:i番目の質問, i:カウンタ
  int q, M, i;
  // cout << dp[1][0] << endl;

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