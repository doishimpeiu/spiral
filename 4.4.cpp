#include <bits/stdc++.h>
using namespace std;

// https://rainbow-engine.com/cpp-arrow-operator-intro/
// アロー演算子（「->」）は構造体や共用体の要素にアクセスするために使います。
// その際に、構造体や共用体を指す「ポインタ」の変数とともに使われます。

// ドット「.」は構造体（structure）や共用体（union）のメンバ（変数や関数）にアクセスするために使用します。
// 一方でアロー演算子「->」は「ポインタ」から構造体や共用体にアクセスする際に使われます。

// ポインタ自体は変数の「アドレス」を保持しているものですが、アロー演算子を使う事によりポインタ経由でもオブジェクトのメンバ（変数や関数）にアクセスできます。

struct Node {
  int key;
  Node *next, *prev;
};

Node *nil;

Node* listSearch(int key) {
  Node *cur = nil->next;  //番兵の次の要素から辿る
  while (cur != nil && cur->key != key) {
    cur = cur->next;
  }
  return cur;
}

void init() {
  nil = (Node *)malloc(sizeof(Node));
  nil->next = nil;
  nil->prev = nil;
}

void printList() {
  Node *cur = nil->next;
  int isf = 0;
  while(1) {
    if(cur == nil) break;
    if(isf++ > 0) printf(" ");
    printf("%d", cur->key);
    cur = cur->next;
  }
  printf("\n");
}

void deleteNode(Node *t) {
  if(t == nil) return;  //tが番兵の場合は処理しない
  t->prev->next = t->next;
  t->next->prev = t->prev;
  free(t);
}

void deleteFirst() {
  deleteNode(nil->next);
}
void deleteLast() {
  deleteNode(nil->prev);
}

void deleteKey(int key){
  //検索したノードを削除
  deleteNode(listSearch(key));
}

void insert(int key){
  Node *x = (Node *)malloc(sizeof(Node));
  x->key = key;
  //番兵の直後に要素を追加
  x->next = nil->next;
  nil->next->prev = x;
  nil->next = x;
  x->prev = nil;
}

int main() {
  int key, n, i;
  int size = 0;
  char com[20];
  int np = 0, nd = 0;
  scanf("%d", &n);
  init();
  for(i = 0; i < n; i++) {
    scanf("%s%d", com, &key);  //より高速な入力関数を使用
    if (com[0] == 'i') {insert(key); np++; size++;}
    else if (com[0] == 'd') {
      if(strlen(com) > 6) {
        if(com[6] == 'F') deleteFirst();
        else if(com[6] == 'L') deleteLast();
      } else {
        deleteKey(key); nd++;
      }
      size--;
    }
  }

  printList();

  return 0;
}