#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool func2(string a, string b){
	string res = "", res2 = "";
	res = a;
	res += b;
	res2 = b;
	res2 += a;
	if(atoi(res.c_str()) > atoi(res2.c_str()))
		return true;
	return false;
}

int main(){
	int N, i, j, k;
	string temp;
	cin >> N;
	while(N != 0){
		vector <string> numbers;
		for(i = 0; i < N; i++){
			cin >> temp;
			numbers.push_back(temp);
		}

		sort(numbers.begin(), numbers.end(), func2);

		for(i = 0; i < N; i++)
			cout << numbers[i] << " ";

		cout << endl;

		cin >> N;
	}

	return 0;
}