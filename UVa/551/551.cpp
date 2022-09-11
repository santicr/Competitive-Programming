#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct signo{
	int pos;
	char bracket;
};

int main(){
	string str;
	while(getline(cin, str)){
		int j = 1;
		stack <signo> pila;
		bool paso = false;
		for(int i = 0; i < str.size(); i++){
			if(str[i] == '[' || str[i] == '<' || str[i] == '{' || str[i] == '('){
				signo temp;
				temp.bracket = str[i];
				temp.pos = j;
				pila.push(temp);
				j++;
			}
			else if(str[i] == ']' || str[i] == '>' || str[i] == '}' || str[i] == ')'){
				signo temp;
				temp.pos = j;
				temp.bracket = str[i];
				if(temp.bracket == ']'){
					if(pila.empty()){
						cout << "NO " << j<< endl;
						paso = true;
						break;
					}
					else if(pila.top().bracket != '['){
						cout << "NO " << j << endl;
						paso = true;
						break;
					}
					pila.pop();
					j++;
				}
				else if(temp.bracket == ')'){
					if(pila.empty()){
						cout << "NO " << j << endl;
						paso = true;
						break;
					}
					else if(pila.top().bracket != '('){
						cout << "NO " << j << endl;
						paso = true;
						break;
					}
					pila.pop();
					j++;
				}
				else if(temp.bracket == '}'){
					if(pila.empty()){
						cout << "NO " << j << endl;
						paso = true;
						break;
					}
					else if(pila.top().bracket != '{'){
						cout << "NO " << j << endl;
						paso = true;
						break;
					}
					pila.pop();
					j++;
				}
				else if(temp.bracket == '>'){
					if(pila.empty()){
						cout << "NO " << j << endl;
						paso = true;
						break;
					}
					else if(pila.top().bracket != '<'){
						cout << "NO " << j << endl;
						paso = true;
						break;
					}
					pila.pop();
					j++;
				}
			}
			else if(str[i] == '*'){
				if(str[i - 1] == '('){
					signo temp;
					temp.bracket = '*';
					temp.pos = pila.top().pos;
					pila.push(temp);
				}
				else if(str[i - 1] != '(' && str[i + 1] == ')'){
					if(pila.empty()){
						cout << "NO " << j << endl;
						paso = true;
						break;
					}
					else if(pila.top().bracket != '*'){
						cout << "NO " << j << endl;
						paso = true;
						break;
					}
					pila.pop();
				}
				else
					j++;
			}
			else
				j++;
		}
		if(pila.empty() && paso == false)
			cout << "YES" << endl;
		if(!pila.empty() && paso == false)
			cout << "NO " << j << endl;
	}

	return 0;
}