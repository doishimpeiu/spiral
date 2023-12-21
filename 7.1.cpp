#include<bits/stdc++.h>
using namespace std;

#define MAX 500000
#define SENTINEL 2000000000  //SENTINEL:番兵

int L[MAX/2+2], R[MAX/2+2];
int cnt;  //比較回数

//統合する関数
void merge(int A[], int n, int left, int mid, int right) {
  int n1 = mid - left;  //左の配列の要素数
  int n2 = right - mid;  //右の配列の要素数
  for(int i = 0; i < n1; i++) L[i] = A[left + i];
  for(int i = 0; i < n2; i++) R[i] = A[mid + i];
  L[n1] = R[n2] = SENTINEL;  //左と右の配列の最後に番兵を入れる
  int i = 0, j = 0;
  for (int k = left; k < right; k++) {
    cnt++;
    if(L[i] <= R[j]) {  //左の配列の要素 が 右の配列の要素の大きさ以下の時
      A[k] = L[i++];  //配列AにL[i]を代入してi++
    } else {
      A[k] = R[j++];  
    }
  }
}

//分割する関数
void mergeSort(int A[], int n, int left, int right){
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergeSort(A, n, left, mid);  //左
    mergeSort(A, n, mid, right);  //右
    merge(A, n, left, mid, right);  //統合する関数
  }
}

int main() {
  int A[MAX], n, i;
  cnt = 0;

  cin >> n;
  for (i = 0; i < n; i++) cin >> A[i];

  mergeSort(A, n, 0, n);

  for(i = 0; i < n; i++) {
    if (i) cout << " ";  //iが0以外の時は前に空白を入れる
    cout << A[i];
  }
  cout << endl;

  cout << cnt << endl;

  return 0;
}