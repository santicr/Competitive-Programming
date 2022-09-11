#include <iostream>
#include <string>

using namespace std;

int main(){
	int L;
	cin >> L;
	while(L != 0){
		for(int i = 0; i < L - 1; i++){
			string temp;
			cin >> temp;
			cout << temp << endl;
		}
		cin >> L;
	}
	return 0;
}