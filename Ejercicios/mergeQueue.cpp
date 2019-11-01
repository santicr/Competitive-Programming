#include <iostream>
#include <queue>

using namespace std;

void printQueue(queue <int> a){
	while(!a.empty()){
		cout << a.front() << endl;
		a.pop();
	}
}

queue <int> mergeQueue(queue <int> a, queue <int> b){
	queue <int> res;
	bool termino = false;
	while(!a.empty()){
		if(termino == true){
			res.push(a.front());
			a.pop();
		}
		else if(a.front() <= b.front()){
			res.push(a.front());
			a.pop();
		}
		else if(a.front() > b.front()){
			res.push(b.front());
			b.pop();
		}
		if(b.empty()){
			termino = true;
		}
	}
	while(!a.empty()){
		res.push(a.front());
		a.pop();
	}
	while(!b.empty()){
		res.push(b.front());
		b.pop();
	}

	return res;
}

int main(){
	queue <int> a, b;
	a.push(4);
	b.push(2);
	a.push(5);
	b.push(2);
	a.push(6);
	b.push(2);
	queue <int> res = mergeQueue(a, b);
	printQueue(res);
	return 0;
}