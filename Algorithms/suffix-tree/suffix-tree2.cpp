/*
Carlos Ramírez
Noviembre 27 de 2020

Implementación Suffix Tree

*/

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
 
using namespace std;

string sigma, s;
int sigmaSize = 40;

struct Node{
  int depth, begin, end, suffixIndex;
  int children[40];
  int parent, suffixLink;

  Node(){}

  Node(int begin, int end, int depth, int parent){
    for(int i = 0; i < sigmaSize; ++i)
      children[i] = -1;
    this->begin = begin;
    this->end = end;
    this->parent = parent;
    this->depth = depth;
    suffixLink = -1;
    suffixIndex = -1;
  }

  bool contains(int d){
    return depth <= d && d < depth + (end - begin);
  }

  int length(){
    return end - begin;
  }
};

Node tree[3000];

string get(int l, int r){
  int i;
  string cad = "";

  for(i = l; i < r; ++i)
    cad.push_back(s[i]);

  return cad;
}

void suffixIndexDFS(int n, string ac, int h){
  int i;
  bool leaf = true;

  printf("Nodo %d %d\n", tree[n].begin, tree[n].end);
  ac += get(tree[n].begin, tree[n].end);

  for(i = 0; i < sigmaSize; i++){
    if(tree[n].children[i] != -1){
      leaf = false;
      suffixIndexDFS(tree[n].children[i], ac, h + tree[tree[n].children[i]].length());
    }
  }

  if(leaf){
    tree[n].suffixIndex = s.size() - h;
    printf("Hoja %d %d %s [%d]\n", tree[n].begin, tree[n].end, ac.c_str(), tree[n].suffixIndex);
  }
}

void buildSuffixTree(){
  int n = s.length(), i, cur, curDepth, k, end, lastRule, remSuffix;
  int *a = new int[n];
  int curr, pos = 0, activeNode = -1;

  for(i = 0; i < n; i++)
    a[i] = sigma.find(s[i]);

  curr = pos;
  tree[pos++] = Node(0, 0, 0, 0); 
  tree[0].suffixLink = 0;
  lastRule = remSuffix = 0;

  for(i = 0; i < n; ++i){
    cur = a[i];

    while(remSuffix <= i){
      curDepth = i - remSuffix;

      if(lastRule != 3){
	if(tree[curr].suffixLink != -1)
	  curr = tree[curr].suffixLink;
	else
	  curr = tree[tree[curr].parent].suffixLink;

	k = remSuffix + tree[curr].depth;
	while(curDepth > 0 && !tree[curr].contains(curDepth - 1)){
	  k += tree[curr].end - tree[curr].begin;
	  curr = tree[curr].children[a[k]];
	}
      }

      if(!tree[curr].contains(curDepth)){
	if(activeNode != -1){
	  tree[activeNode].suffixLink = curr;
	  activeNode = -1;
	}

	if(tree[curr].children[cur] == -1){
	  tree[pos++] = Node(i, n, curDepth, curr);
	  tree[curr].children[cur] = pos - 1;
	  lastRule = 2;
	}
	else{
	  curr = tree[curr].children[cur];
	  lastRule = 3;
	  break;
	}
      }
      else{
	end = tree[curr].begin + curDepth - tree[curr].depth;

	if(a[end] != cur){
	  tree[pos++] = Node(tree[curr].begin, end, tree[curr].depth, tree[curr].parent);
	  int newn = pos - 1;
	  tree[pos++] = Node(i, n, curDepth, newn);
	  tree[newn].children[cur] = pos - 1;
	  tree[newn].children[a[end]] = curr;
	  tree[tree[curr].parent].children[a[tree[curr].begin]] = newn;

	  if(activeNode != -1)
	    tree[activeNode].suffixLink = newn;
	  tree[curr].begin = end;
	  tree[curr].depth = curDepth;
	  tree[curr].parent = newn;
	  curr = activeNode = newn;
	  lastRule = 2;
	}
	else if(tree[curr].end != n || (tree[curr].begin - tree[curr].depth) < remSuffix){
	  lastRule = 3;
	  break;
	}
	else
	  lastRule = 1;
      }

      remSuffix += 1;
    }
  }
  
  tree[0].suffixLink = -1;
  
  suffixIndexDFS(0, "", 0);
}

int main(){
  sigma = "abcdefghijklmnopqrstuvwxyz$";
  sigmaSize = sigma.length();
  s = "atgctga$";
  buildSuffixTree();

  return 0;
}
