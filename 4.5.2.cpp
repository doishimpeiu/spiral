//スタックの使い方
#include <bits/stdc++.h>
using namespace std;

int main() {
  stack<int> S;

  S.push(3);
  S.push(7);
  S.push(1);
  cout << S.size() << " ";

  cout << S.top() << " ";
  S.pop();

  cout << S.top();
  S.pop();

  cout << S.top();

  S.push(5);

  cout << S.top();
  S.pop();

  cout << S.top() << endl;

  return 0;
}