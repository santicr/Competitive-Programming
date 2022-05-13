/*
Carlos Ramírez
Noviembre 18 de 2020

Implementación Fenwick Tree (sum)
Range Update and Position Query

*/

#include <cstdio>
#include <cstdlib>
#include <vector>

int MAX = 1000;

int tree[1000];

void add(int, int, int);
void rangeAdd(int, int, int, int);
int query(int);

//build
void build(int *a, int n){
  for(int i = 0; i < n; ++i)
    tree[i] = 0;
  
  for(int i = 0; i < n; ++i)
    rangeAdd(i, i, a[i], n);
}

//update the Fenwick tree
void add(int idx, int val, int n){
  while(idx < n){
    tree[idx] += val;
    idx = idx | (idx + 1);
  }
}

void rangeAdd(int l, int r, int val, int n){
  add(l, val, n);
  add(r + 1, -val, n);
}

//simple query
int query(int r){
  int res = 0;
  while(r >= 0){
    res += tree[r];
    r = (r & (r + 1)) - 1;
  }
  return res;
}

int main(){
  int i, n = 8;
  int a[] = {2, 6, 7, 1, 3, 5, 8, 4};
  build(a, n);

  for(i = 0; i < n; ++i)
    printf("%d%c", tree[i], (i == n - 1) ? '\n' : ' ');

  printf("%d\n", query(1));
  printf("%d\n", query(2));
  printf("%d\n", query(5));
  printf("%d\n", query(6));
  printf("%d\n", query(7));
  rangeAdd(2, 4, 10, n);

  for(i = 0; i < n; ++i)
    printf("%d%c", tree[i], (i == n - 1) ? '\n' : ' ');

  rangeAdd(4, 6, 8, n);

  for(i = 0; i < n; ++i)
    printf("%d%c", tree[i], (i == n - 1) ? '\n' : ' ');

  printf("%d\n", query(5));
  printf("%d\n", query(6));
  printf("%d\n", query(4));

  return 0;
}


