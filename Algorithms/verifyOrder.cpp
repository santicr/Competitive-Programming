#include <iostream>
#include <stack>

using namespace std;

bool verifyOrder(stack <int> pila){
	bool mayor = false;
	bool menor = false;
	stack <int> res;
	while(!pila.empty()){
		if(res.empty()){
			res.push(pila.top());
			pila.pop();
		}
		else if(!res.empty()){
			if(pila.top() > res.top()){
				res.push(pila.top());
				pila.pop();
				menor = true;
			}
			else if(pila.top() == res.top()){
				res.push(pila.top());
				pila.pop();
			}
			else if(pila.top() < res.top()){
				res.push(pila.top());
				pila.pop();
				mayor = true;
			}
		}
	}
	if(mayor == true && menor == true)
		return false;
	else if((mayor == true && menor == false) || (menor == true && mayor == false))
		return true;
	return false;
}

int main(){
	stack <int> pila;
	pila.push(1);
	pila.push(2);
	pila.push(3);
	pila.push(3);
	pila.push(3);
	cout << verifyOrder(pila) << endl;
	return 0;
}