/*
Carlos Ramírez
Noviembre 27 de 2020

Implementación Suffix Tree

*/

#include <bits/stdc++.h>
 
using namespace std;

string sigma, s, str;
int sigmaSize = 5;

struct Node{
	int depth, begin, end, suffixIndex;
	int children[5];
	int parent, suffixLink;

	Node(){}

	Node(int begin, int end, int depth, int parent, int suf){
		for(int i = 0; i < sigmaSize; ++i)
			children[i] = -1;
		this->begin = begin;
		this->end = end;
		this->parent = parent;
		this->depth = depth;
		suffixLink = -1;
		suffixIndex = suf;
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

void suffixIndexDFS(int n, string ac, int x){
	int i;
	bool leaf = true;
	ac += get(tree[n].begin, tree[n].end);

	for(i = 0; i < sigmaSize; i++){
		if(tree[n].children[i] != -1){
			if(x >= 1 && ac.size() > str.size())
				str = ac;
			leaf = false;
			suffixIndexDFS(tree[n].children[i], ac, x + 1);
		}
	}
}

void buildSuffixTree(){
	int n = s.length(), i, cur, curDepth, k, end, lastRule, remSuffix;
	int *a = new int[n];
	int curr, pos = 0, activeNode = -1;

	for(i = 0; i < n; i++)
		a[i] = sigma.find(s[i]);

	curr = pos;
	tree[pos++] = Node(0, 0, 0, 0, -1); 
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
					tree[pos++] = Node(i, n, curDepth, curr, i);
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
					tree[pos++] = Node(tree[curr].begin, end, tree[curr].depth, tree[curr].parent, -1);
					int newn = pos - 1;
					tree[pos++] = Node(i, n, curDepth, newn, i);
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
	sigma = "ACGT$";
	sigmaSize = sigma.length();
	int casos;
	cin >> casos;

	while(casos--){
		cin >> s;
		s += '$';
		buildSuffixTree();
		if(str.size() == 0)
			cout << "No repetitions found!" << endl;
    	else{
			string aux;
			int num = 0;
			for(int i = 0; i < s.size(); i++){
				aux = s.substr(i, str.size());
				if(aux == str)
					num++;
			}
			cout << str << " " << num << endl;
		}
		str = "";
	}

	return 0;
}
