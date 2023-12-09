#include <bits/stdc++.h>
using namespace std;

void sqrt(int* x, int* y);

int main() {
  int x = 10;

  cout << &x << endl;  //参照：&変数でアドレスを示す

  int* xPtr;  //ポインタを宣言
  xPtr = &x;  //ポインタに変数xのアドレスを代入する→ポインタはアドレスの箱みたいなもの

  cout << xPtr << endl;  //ポインタに代入されているアドレスを出力
  cout << *xPtr << endl;  //*をポインタにつけることでポインタに格納されているアドレスの変数の値を出力

  int y = 10;
  int *yPtr = &y;  //こういう宣言のしかたもある

  cout << *yPtr << endl;

  sqrt(xPtr, yPtr);  //アドレスを渡すのだから*がついていないということ

  cout << *yPtr << endl;

  return 0;
}

void sqrt(int* x, int* y) {
  *y = *x * *y;
}