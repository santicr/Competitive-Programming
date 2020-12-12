#include <bits/stdc++.h>
 
using namespace std;

string sigma, s, str;
int sigmaSize = 27, val;
set <string> res;

struct Node{
	int depth, begin, end, suffixIndex;
	int children[27];
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
	int i, pos = tree[n].begin;
	bool leaf = true;
	ac += get(tree[n].begin, tree[n].end);

	for(i = 0; i < sigmaSize; i++){
		if(tree[n].children[i] != -1){
			if(x >= 1){
				str = ac;
				res.insert(ac);
			}

			leaf = false;
			suffixIndexDFS(tree[n].children[i], ac, x + 1);
		}
	}
	if(leaf){

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

bool es(string aux, int tam){
	int sz = aux.size();
	for(int i = 0; i < tam; i++){
		if(s.substr(i, sz) == aux)
			return true;
	}
	return false;
}

int main(){
	sigma = "abcdefghijklmnopqrstuvwxy$";
	sigmaSize = sigma.length();
    string aux, temp;
	int index = 0;

	while(cin >> s){
        cin >> aux;
		if(index++ != 0)
			cout << endl;
        val = s.size();
        set <string> :: iterator it;
        s += '#';
		s += aux;
        s += '$';
		int tam = -1, size = s.size(), size2;
		set <string> respuesta;
        buildSuffixTree();

		for(it = res.begin(); it != res.end(); it++){
			size2 = it -> size();
			for(int i = val; i < size; i++){
				if(s.substr(i, size2) == *it && es(*it, val) && tam < size2){
					respuesta.clear();
					respuesta.insert(*it);
					tam = size2;
				}
				else if(s.substr(i, size2) == *it && es(*it, val) && tam == size2)
					respuesta.insert(*it);
			}
		}

		for(it = respuesta.begin(); it != respuesta.end(); it++)
			cout << *it << endl;
		if(respuesta.empty())
			cout << "No common sequence." << endl;

		res.clear();
	}

	return 0;
}
