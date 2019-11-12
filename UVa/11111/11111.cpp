#include <stack>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

struct p{
	int num;
	int sum = 0;
};

bool func(vector <p> vec){
	stack <p> pila;
	for(int i = 0; i < vec.size(); i++){
		if(vec[i].num < 0)
			pila.push(vec[i]);
		else if(vec[i].num > 0){
			if(pila.empty())
				return false;
			if(-(vec[i].num) != pila.top().num)
				return false;
			pila.pop();
			if(!pila.empty()){
				pila.top().sum += vec[i].num;
				if(pila.top().sum >= -(pila.top().num))
					return false;
			}
		}
	}
	if(pila.empty())
		return true;
	return false;
}

int main(){
	string str;
	while(getline(cin, str)){
		vector <p> vec;
		int indice = 0;
		for(int i = 0; i < str.size(); i++){
			if(str[i] == ' '){
				p temp;
				temp.num = atoi(str.substr(indice, i - indice).c_str());
				vec.push_back(temp);
				indice = i + 1;
			}
			if(i == str.size() - 1){
				p temp;
				temp.num = atoi(str.substr(indice, str.size() - indice).c_str());
				vec.push_back(temp);
			}
		}
		if(func(vec))
			cout << ":-) Matrioshka!" << endl;
		else
			cout << ":-( Try again." << endl;
 	}

	return 0;
}