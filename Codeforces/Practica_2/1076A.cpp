//Accepted
#include <bits/stdc++.h>

using namespace std;

int main(){
	int size, pos;
	char max;
	string str, ans;
	
	cin >> size;
	cin >> str;

	pos = size - 1;

	for(int i = 0; i < size; i++){
		if(i + 1 < size && str[i] > str[i + 1]){
			pos = i;
			break;
		}
	}

	str.erase(pos, 1);

	cout << str << endl;

	return 0;
}