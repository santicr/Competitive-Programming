#include <bits/stdc++.h>

using namespace std;

int main(){
	int subNum, subId;
	float delay;
	string horas, str;

	cin >> subNum >> delay;

	while(subNum--){
		cin >> subId;
		getline(cin, str);
		while(str != "\n"){
			cout << str << endl;
			getline(cin, str);
		}
		printf("Salio\n");
	}

	return 0;
}