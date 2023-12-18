#include <bits/stdc++.h>
using namespace std;
int MAX = 10000;

int binarySearch(int A[], int n, int key){
  int left = 0;
  int right = n;
  while (left < right) {
    int mid = (left + right) / 2;
    // cout << "mid:" << mid << endl;
    if (A[mid] == key)  {
      // cout << key << endl;
      // return mid;  midを返すと配列の先頭が一致する時0を返してしまい, 見つかっていないことになる
      return 1;
    }
    else if(key < A[mid]) right = mid;
    else left = mid + 1;
  }
  return 0;
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
    if(binarySearch(S, n, key)){
      sum++;
      // cout << sum << endl;
    } 
  }

  cout << sum << endl;

  return 0;
}