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
		cout << str << endl;
	}


	return 0;
}