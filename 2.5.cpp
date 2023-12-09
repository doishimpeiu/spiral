#include <bits/stdc++.h>
using namespace std;

static const int MAX = 200000;

int main() {
  int R[MAX], n;

  cin >> n;
  for (int i = 0; i < n; i++) cin >> R[i];

  int maxv = -2000000000;  //十分小さい値を初期値に設定
  int minv = R[0];

  for (int i = 1; i < n; i++) {
    maxv = max(maxv, R[i] - minv);
    minv = min(minv, R[i]);
    // cout << "i, maxv, minv" << ":" << i << "," << maxv <<"," << minv << endl;
    cout << "i:" << i << "," << "maxv:" << maxv << "," << "minv:" << minv << endl;
  }

  cout << maxv << endl;

  return 0;
}