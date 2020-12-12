/*
Carlos Ramírez
Noviembre 18 de 2020

Implementación Fenwick Tree (sum)
Range Update and Range Query

*/

#include <cstdio>
#include <cstdlib>
#include <vector>

int tree1[1000], tree2[1000];

void add(int*, int, int, int);
void rangeAdd(int, int, int, int);
int query(int);

//build
//void build(int *a, int n){
void build(int n){
  for(int i = 0; i < n; ++i)
    tree1[i] = tree2[i] = 0;
  //for(int i = 0; i < n; ++i)
  //rangeAdd(i, i, a[i], n);
}

//update the Fenwick tree
void add(int *a, int idx, int val, int n){
  while(idx < n){
    a[idx] += val;
    idx = idx | (idx + 1);
  }
}

void rangeAdd(int l, int r, int val, int n){
  add(tree1, l, val, n);
  add(tree1, r + 1, -val, n);
  add(tree2, l, val * (l - 1), n);
  add(tree2, r + 1, -val * r, n);
}

//simple query
int query(int *a, int r){
  int res = 0;
  while(r >= 0){
    res += a[r];
    r = (r & (r + 1)) - 1;
  }
  return res;
}

int prefixQuery(int idx){
  return query(tree1, idx) * idx - query(tree2, idx);
}

int rangeQuery(int l, int r){
  return prefixQuery(r) - prefixQuery(l - 1);
}

int main(){
  int i, n = 8;
  //int a[] = {2, 6, 7, 1, 3, 5, 8, 4};
  //build(a, n);
  build(n);

  for(i = 0; i < n; ++i)
    printf("%d%c", tree1[i], (i == n - 1) ? '\n' : ' ');

  for(i = 0; i < n; ++i)
    printf("%d%c", tree2[i], (i == n - 1) ? '\n' : ' ');

  rangeAdd(2, 4, 10, n);

  for(i = 0; i < n; ++i)
    printf("%d%c", tree1[i], (i == n - 1) ? '\n' : ' ');

  for(i = 0; i < n; ++i)
    printf("%d%c", tree2[i], (i == n - 1) ? '\n' : ' ');
  
  printf("%d\n", rangeQuery(0, 3));
  printf("%d\n", rangeQuery(0, 7));

  rangeAdd(4, 6, 8, n);

  for(i = 0; i < n; ++i)
    printf("%d%c", tree1[i], (i == n - 1) ? '\n' : ' ');

  for(i = 0; i < n; ++i)
    printf("%d%c", tree2[i], (i == n - 1) ? '\n' : ' ');
  
  printf("%d\n", rangeQuery(0, 4));
  printf("%d\n", rangeQuery(0, 7));
  
  return 0;
} 


