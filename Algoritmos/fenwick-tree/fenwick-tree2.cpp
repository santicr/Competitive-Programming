/*
Carlos Ramírez
Noviembre 18 de 2020

Implementación Fenwick Tree (max, min)

*/

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <climits>

using namespace std;

int MAX = 1000;

int tree[1000];

void update(int, int, int);
int query(int);

//build
void build(int *a, int n){
  int i;
  
  for(i = 0; i < n; ++i)
    tree[i] = INT_MIN;
  
  for(i = 0; i < n; ++i)
    update(i, a[i], n);
}

//update the Fenwick tree
void update(int idx, int val, int n){
  while(idx < n){
    tree[idx] = max(tree[idx], val);
    idx = idx | (idx + 1);
  }
}

//simple query
int query(int r){
  int res = INT_MIN;
  while(r >= 0){
    res = max(res, tree[r]);
    r = (r & (r + 1)) - 1;
  }
  return res;
}

int main(){
  int i, n = 8;
  int a[] = {2, 4, 8, 2, 5, 3, 1, 7};
  build(a, n);

  for(i = 0; i < n; ++i)
    printf("%d%c", tree[i], (i == n - 1) ? '\n' : ' ');

  printf("%d\n", query(5));
  printf("%d\n", query(6));
  printf("%d\n", query(1));

  return 0;
}


