#include <bits/stdc++.h>
using namespace std;

static const int MAX = 100;
int Q[MAX];
int head, tail;

void initialize(){
  head = tail = 0;
}
int isEmpty() {
  return head == tail;
}
int isFull() {
  return head == (tail+1) % MAX;
}
void enqueue(int x){
  if (isFull()) {
    cout << "エラー(オーバーフロー)" << endl;
  } else {
    Q[tail] = x;
    if(tail + 1 == MAX) tail = 0;
    else tail++;
  }
}
int dequeue(){
  int x;
  if(isEmpty()){
    cout << "エラー(アンダーフロー)" << endl;
  } else {
    x = Q[head];
    if(head + 1 == MAX) head = 0;
    else head++;
  }
  return x;
}

int main() {
  initialize();
  enqueue(1);
  enqueue(2);
  cout << Q[head] << Q[head + 1] << endl;
  int x = dequeue();
  cout << Q[head] << Q[tail] << endl;
  return 0;
}