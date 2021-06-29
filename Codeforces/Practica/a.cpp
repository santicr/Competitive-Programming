//Accepted
#include <bits/stdc++.h>

using namespace std;

int main(){
	string input;
	vector <int> vec;

	cin >> input;

	for(int i = 0; i < input.size(); i += 2)
		vec.push_back(input[i] - '0');
	sort(vec.begin(), vec.end());

	for(int i = 0; i < vec.size(); i++){
		if(i == 0)
			cout << vec[i];
		else
			cout << "+" << vec[i];
	}


	return 0;
}