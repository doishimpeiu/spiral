#include<bits/stdc++.h>
using namespace std;
static const int MAX = 100;
int S[MAX];
int top;

void initialize(){
  top = 0;
}
int isEmpty(){
  return top == 0;
}
int isFull(){
  return top >= MAX - 1;
}
void push(int x){
  if (isFull()){
    cout << "エラー(オーバーフロー)" << endl;
  } else {
    top++;
    S[top] = x;
  }
}
int pop() {
  if (isEmpty()){
    cout << "エラー(アンダーフロー)" << endl;
    return 0;
  } else {
    top--;
    return S[top+1];
  }
}


int main() {
  initialize();
  // push(1);
  // push(2);
  // cout << S[top] << endl;
  // pop();
  // cout << S[top] << endl;

  return 0;
}