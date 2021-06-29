#include <bits/stdc++.h>

using namespace std;

long long int x, a;

int main(){
	int cases;
	bool flag = false;
	cin >> cases;

	while(cases--){
		cin >> x;
		
		for(long long int i = 1; i <= 9999; i++){
			a = cbrt(x - (i * i * i));
			
			if(a <= 0)
				break;
			if((a * a * a)+ (i * i * i) == x){
				flag = true;
				cout << "YES" << endl;
				break;
			}
		}

		if(!flag)
			cout << "NO" << endl;
		if(flag)
			flag = false;
	}

	return 0;
}