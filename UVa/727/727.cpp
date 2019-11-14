#include <iostream>
#include <stack>
#include <string>

using namespace std;

int valor(char car){
	if(car == '*' || car == '/')
		return 2;
	else if(car == '+' || car == '-')
		return 1;
	return 0;
}

int main(){
	int cases;
	scanf("%d\n", &cases);
	while(cases--){
		stack <char> pila;
		string str1, str;
		while(getline(cin, str1)){
			if(str1.size() == 0)
				break;
			str.push_back(str1[0]);
		}
		for(int i = 0; i < str.size(); i++){
			if(str[i] == '*' || str[i] == '+' || str[i] == '-' || str[i] == '/'){
				if(pila.empty() || valor(str[i]) > valor(pila.top()))
					pila.push(str[i]);
				else{
					while(!(valor(pila.top()) < valor(str[i]))){
						cout << pila.top();
						pila.pop();
						if(pila.empty())
							break;
					}
					pila.push(str[i]);
				}
			}
			else if(str[i] == '(')
				pila.push(str[i]);
			else if(str[i] == ')'){
				while(pila.top() != '('){
					cout << pila.top();
					pila.pop();
				}
				pila.pop();
			}
			else
				cout << str[i];
		}
		while(!pila.empty()){
			cout << pila.top();
			pila.pop();
		}
		cout << endl;
		if(cases != 0)
			cout << endl;
	}


	return 0;
}