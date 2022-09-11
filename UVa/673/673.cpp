#include <iostream>
#include <stack>

using namespace std;

bool func(string str){
	stack <char> pila;
	for(int i = 0; i < str.size(); i++){
		if(str[i] == '(' || str[i] == '[')
			pila.push(str[i]);
		else if(str[i] == ')'){
			if(pila.empty())
				return false;
			if(pila.top() != '(')
				return false;
			pila.pop();
		}
		else if(str[i] == ']'){
			if(pila.empty())
				return false;
			if(pila.top() != '[')
				return false;
			pila.pop();
		}
	}
	if(!pila.empty())
		return false;
	return true;
}

int main(){
	int cases;
	cin >> cases;
	cin.ignore();
	while(cases--){
		string str;
		getline(cin, str);
		if(func(str))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}