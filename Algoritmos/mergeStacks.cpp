#include <stack>
#include <iostream>

using namespace std;

stack <int> mergeStacks(stack <int> pil1, stack <int> pil2){
	stack <int> res;
	stack <int> res2;
	
	if(pil1.size() > pil2.size()){
		while(!pil1.empty()){
			if(pil2.empty())
				break;
			else if(pil1.top() < pil2.top()){
				res.push(pil1.top());
				pil1.pop();
			}
			else if(pil1.top() >= pil2.top()){
				res.push(pil2.top());
				pil2.pop();
			}
		}
	}

	else{
		while(!pil2.empty()){
			if(pil1.empty())
				break;
			else if(pil2.top() < pil1.top()){
				res.push(pil2.top());
				pil2.pop();
			}
			else if(pil2.top() >= pil1.top()){
				res.push(pil1.top());
				pil1.pop();
			}
		}
	}

	while(!pil1.empty() || !pil2.empty()){
		if(pil1.size() > 0){
			res.push(pil1.top());
			pil1.pop();
		}
		else if(pil2.size() > 0){
			res.push(pil2.top());
			pil2.pop();
		}
	}

	while(!res.empty()){
		res2.push(res.top());
		res.pop();
	}

	return res2;
}

void printStack(stack <int> pil1){
	while(!pil1.empty()){
		cout << pil1.top() << endl;
		pil1.pop();
	}
}

int main(){
	stack <int> pil1, pil2, pil3;
	pil1.push(9);
	pil1.push(8);
	pil1.push(7);
	pil1.push(6);
	pil1.push(5);
	pil1.push(4);
	pil1.push(3);

	pil2.push(3);
	pil2.push(2);
	pil2.push(1);

	pil3 = mergeStacks(pil1, pil2);
	cout << pil1.size() << " tamaño 1" << endl;
	cout << pil2.size() << " tamaño 2" << endl;
	cout << pil3.size() << " tamaño 3" << endl;
	printStack(pil3);


	return 0;
}