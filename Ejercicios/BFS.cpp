#include <vector>
#include <map>
#include <string>
#include <cstdio>
#include <iostream>

using namespace std;

vector<vector<int>> adj(10000);
bool visitados[1000];
int p[1000];
vector <int> res;

void bfs(int v, int final){
  int u, w, i;
  queue<int> cola;
  visitados[v] = true;
  cola.push(v);

  while(!cola.empty()){
    u = cola.front();
    cola.pop();
    res.push_back(u);
    if(u == final)
      return;

    for(i = 0; i < adj[u].size(); ++i){
      w = adj[u][i];
      if(!visitados[w]){
        visitados[w] = true;
        cola.push(w);
      }
    }
  }
}