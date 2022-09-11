/*
Carlos Ramírez
Noviembre 18 de 2020

Implementación Fenwick Tree 2D (sum)

*/

#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

int MAX = 1000, m = 8;
int tree[1000][1000];

int a[][8] = {{2, 4, 8, 2, 5, 3, 1, 7},
	      {5, 1, 3, 5, 10, 6, 7, 9},
	      {4, 2, 1, 7, 8, 7, 5, 0},
	      {9, 1, 1, 1, 3, 2, 6, 4},
	      {7, 12, 11, 5, 4, 3, 2, 7},
	      {7, 12, 11, 5, 4, 3, 2, 7},
	      {5, 1, 3, 5, 10, 6, 7, 9},
	      {0, 0, 3, 2, 1, 7, 11, 14}};

void add(int, int, int, int, int);
int query(int, int);
int query(int, int, int, int);

//build
void build(int n, int m){
  int i, j;
  //int aux[n][m];

  for(i = 0; i < n; ++i){
    for(j = 0; j < m; ++j){
      //aux[i][j] = tree[i][j];
      tree[i][j] = 0;
    }
  }
  
  for(i = 0; i < n; ++i){
    for(j = 0; j < m; ++j){
      add(i, j, a[i][j], n, m);
    }
  }
}

//update the Fenwick tree
void add(int idx, int idy, int val, int n, int m){
  int z;
  while(idx < n){
    z = idy;
    while(z < m){
      tree[idx][z] += val;
      z = z | (z + 1);
    }
    idx = idx | (idx + 1);
  }
}

//simple query
int query(int x, int y){
  int res = 0, z;
  while(x >= 0){
    z = y;
    while(z >= 0){
      res += tree[x][z];
      z = (z & (z + 1)) - 1;
    }
    x = (x & (x + 1)) - 1;
  }
  return res;
}

//range query
int query(int x1, int y1, int x2, int y2){
  return query(x2, y2) - query(x2, y1 - 1) - query(x1 - 1, y2) + query(x1 - 1, y1 - 1);
}

int main(){
  int i, j, n = 8, m = 8;
	       
  build(n, m);

  for(i = 0; i < n; ++i){
    for(j = 0; j < m; ++j){
      printf("%d%c", tree[i][j], (j == m - 1) ? '\n' : ' ');
    }
  }

  printf("%d\n", query(5, 5));
  printf("%d\n", query(6, 6));
  printf("%d\n", query(2, 2, 6, 6));
  add(3, 3, 10, n, m);

  for(i = 0; i < n; ++i){
    for(j = 0; j < m; ++j){
      printf("%d%c", tree[i][j], (j == m - 1) ? '\n' : ' ');
    }
  }

  printf("%d\n", query(5, 5));

  return 0;
}


