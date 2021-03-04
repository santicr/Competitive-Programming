#include <cstdio>
#include <climits>
#include <list>

using namespace std;

list<int> pila;
int minV, maxV;

void push(int v){
  pila.push_front(v);
  minV = min(v, minV);
  maxV = max(v, maxV);
}

int query(){
  return maxV - minV;
}

void pop(){
  int v = pila.front();
  pila.pop_front();
  if(v == minV){
    minV = maxV;
    for(list<int>::iterator it = pila.begin(); it != pila.end(); ++it)
      minV = min(minV, *it);
  }
  else if(v == maxV){
    for(list<int>::iterator it = pila.begin(); it != pila.end(); ++it)
      maxV = min(maxV, *it);
  }
}

int main(){
  minV = INT_MAX;
  maxV = 0;
  push(10);
  printf("min = %d, max = %d\n", minV, maxV);
  push(15);
  printf("min = %d, max = %d\n", minV, maxV);
  push(10);
  printf("min = %d, max = %d\n", minV, maxV);
  printf("Res = %d\n", query());
  pop();
  printf("min = %d, max = %d\n", minV, maxV);
  pop();
  printf("min = %d, max = %d\n", minV, maxV);

  return 0;
}
