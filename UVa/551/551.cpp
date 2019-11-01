#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

bool verifica(char s){
	if(s == '(' || s == ')' || s == '[' || s == ']' || s == '{' || s == '}' ||
		s == '<' || s == '>'|| s == '*')
		return true;
	return false;
}

int main(){
	string str;
	while(getline(cin, str)){
		stack <char> pilita;
		queue <char> pilita2;
		for(int i = 0; i < str.size(); i++){
			if(verifica(str[i])){
				
			}
		}
	}

	return 0;
}