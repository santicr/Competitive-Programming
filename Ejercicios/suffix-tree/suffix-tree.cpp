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
int sigmaSize;

struct Node{
  int depth, begin, end, suffixIndex;
  Node **children;
  Node *parent, *suffixLink;  

  Node(int begin, int end, int depth, Node *parent){
    children = new Node*[sigmaSize];
    this->begin = begin;
    this->end = end;
    this->parent = parent;
    this->depth = depth;
  }

  bool contains(int d){
    return depth <= d && d < depth + (end - begin);
  }

  int length(){
    return end - begin;
  }
};

string get(int l, int r){
  int i;
  string cad = "";

  for(i = l; i < r; ++i)
    cad.push_back(s[i]);

  return cad;
}

void suffixIndexDFS(Node *n, int h, string ac){
  int i;
  bool leaf = true;

  printf("Nodo %d %d\n", n->begin, n->end);
  ac += get(n->begin, n->end);

  for(i = 0; i < sigmaSize; i++){
    if(n->children[i] != NULL){
      leaf = false;
      suffixIndexDFS(n->children[i], h + n->children[i]->length(), ac);
    }
  }

  if(leaf){
    n->suffixIndex = s.size() - h;
    printf("Hoja %d %d %s [%d]\n", n->begin, n->end, ac.c_str(), n->suffixIndex);
  }
}

Node *buildSuffixTree(){
  int n = s.length(), i, cur, curDepth, k, end, lastRule, remSuffix;
  int *a = new int[n];

  for(i = 0; i < n; i++)
    a[i] = sigma.find(s[i]);

  Node *curr, *root = new Node(0, 0, 0, NULL);
  curr = root;
  root->suffixLink = root;
  Node *activeNode = NULL;
  lastRule = remSuffix = 0;

  for(i = 0; i < n; ++i){
    cur = a[i];

    while(remSuffix <= i){
      curDepth = i - remSuffix;

      if(lastRule != 3){
	if (curr->suffixLink != NULL)
	  curr = curr->suffixLink;
	else
	  curr = curr->parent->suffixLink;

	k = remSuffix + curr->depth;
	while(curDepth > 0 && !curr->contains(curDepth - 1)){
	  k += curr->end - curr->begin;
	  curr = curr->children[a[k]];
	}
      }

      if(!curr->contains(curDepth)){
	if(activeNode != NULL){
	  activeNode->suffixLink = curr;
	  activeNode = NULL;
	}

	if(curr->children[cur] == NULL){
	  curr->children[cur] = new Node(i, n, curDepth, curr);
	  lastRule = 2;
	}
	else{
	  curr = curr->children[cur];
	  lastRule = 3;
	  break;
	}
      }
      else{
	end = curr->begin + curDepth - curr->depth;

	if(a[end] != cur){
	  Node *newn = new Node(curr->begin, end, curr->depth, curr->parent);
	  newn->children[cur] = new Node(i, n, curDepth, newn);
	  newn->children[a[end]] = curr;
	  curr->parent->children[a[curr->begin]] = newn;

	  if(activeNode != NULL)
	    activeNode->suffixLink = newn;
	  curr->begin = end;
	  curr->depth = curDepth;
	  curr->parent = newn;
	  curr = activeNode = newn;
	  lastRule = 2;
	}
	else if(curr->end != n || (curr->begin - curr->depth) < remSuffix){
	  lastRule = 3;
	  break;
	}
	else
	  lastRule = 1;
      }

      remSuffix += 1;
    }
  }

  root->suffixLink = NULL;
  suffixIndexDFS(root, 0, "");

  return root;
}

int main(){
  sigma = "abcdefghijklmnopqrstuvwxyABCDEFGHIJKLMNOPQRSTUVWXYZ$";
  sigmaSize = sigma.length();
  s = "abxabcba$";
  Node* tree = buildSuffixTree();

  return 0;
}
