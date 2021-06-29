#include <bits/stdc++.h>

using namespace std;

list <string> list1, list2;
long long int l, r;

void tobin(){
	while(l > 0 || r > 0){
		if(l != 0)
			list1.push_front(to_string(l % 2));
		if(r != 0)
			list2.push_front(to_string(r % 2));
		l /= 2;
		r /= 2;
	}
}

int main(){

	cin >> l >> r;

	tobin();
	for(auto it = list1.begin(); it != list1.end(); it++)
		cout << *it << " ";
	cout << endl;

	for(auto it = list2.begin(); it != list2.end(); it++)
		cout << *it << " ";
	cout << endl;

	return 0;
}