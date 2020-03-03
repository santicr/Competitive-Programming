#include <bits/stdc++.h>

using namespace std;

void print(vector <int> vec){
	for(int i = 0; i < vec.size(); i++){
		if(i == 0)
			printf("%d", vec[i]);
		else
			printf(" %d", vec[i]);
	}
	printf("\n");
}

int main(){
	int cases;
	cin >> cases;
	while(cases--){
		int n, temp;
		vector <int> neck, brac;
		cin >> n;

		for(int i = 0; i < n; i++){
			cin >> temp;
			neck.push_back(temp);
		}

		for(int i = 0; i < n; i++){
			cin >> temp;
			brac.push_back(temp);
		}

		sort(neck.begin(), neck.end());
		sort(brac.begin(), brac.end());
		
		print(neck);
		print(brac);

	}


	return 0;
}