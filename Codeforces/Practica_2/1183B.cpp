//Accepted
#include <bits/stdc++.h>

using namespace std;

int main(){
	int cases, products, k, temp, min = INT_MAX, max = -1;
	cin >> cases;
	
	while(cases--){
		cin >> products >> k;
		
		for(int i = 0; i < products; i++){
			cin >> temp;
			
			if(temp < min)
				min = temp;

			if(temp > max)
				max = temp;
		}

		if((min + k == max + abs(max - (min + k)) && abs(max - (min + k)) <= k) 
			|| (min + k == max - abs(max - (min + k)) && abs(max - (min + k)) <= k))
			cout << min + k << endl;
		else
			cout << -1 << endl;

		min = INT_MAX;
		max = -1;
	}

	return 0;
}