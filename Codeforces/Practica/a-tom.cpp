//Accepted
#include <bits/stdc++.h>

using namespace std;

string str;
vector <string> vec;
int n, i = 0;

bool busqueda(){
	for(int i = 0; i < vec.size(); i++){
		if(vec[i] == str)
			return true;
	}
	return false;
}

int main(){
	cin >> n;

	while(n--){
		cin >> str;
		if(i++ == 0)
			cout << "NO" << endl;
		else{

			if(busqueda())
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
		vec.push_back(str);
	}


	return 0;
}