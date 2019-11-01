#include <iostream>
#include <stack>
#include <string>
#include <queue>

using namespace std;

bool balance(string str, queue <char> cola, stack <char> pila){
	for(int i = 0; i < str.size(); i++){
		if(str[i] == '[' || str[i] == '(')
			pila.push(str[i]);
		else if(str[i] == ']' || str[i] == ')'){
			cola.push(str[i]);
			if(pila.empty())
				return false;
			if(cola.front() == ']'){
				if(pila.top() != '[' || pila.empty() == true)
					return false;
				cola.pop();
				pila.pop();
			}
			if(cola.front() == ')'){
				if(pila.top() != '(' || pila.empty() == true)
					return false;
				cola.pop();
				pila.pop();
			}
		}
	}
	if(pila.size() > 0 || cola.size() > 0)
		return false;

	return true;
}

int main(){
	int cases, i = 0;
	cin >> cases;
	while(cases--){
		string str, str2;
		queue <char> cola;
		stack <char> pila;
		if(i == 0){
			i++;
			cin.ignore();
		}
		getline(cin, str);
		for(int i = 0; i < str.size(); i++){
			if(str[i] != ' ')
				str2.push_back(str[i]);
		}
		if(balance(str2, cola, pila) || str.size() == 0)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;

	}

	return 0;
}