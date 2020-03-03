#include <bits/stdc++.h>

using namespace std;

int main(){
	vector <long long int> vec;
	long long int number, modulo; 
	long long temp, res = 1;
	cin >> number >> modulo;

	for(int i = 0; i < number; i++){
		cin >> temp;
		vec.push_back(temp);
		if(i > 0){
			if(vec[0] >= temp)
				res *= (vec[0] - temp);
			else
				res *= (temp- vec[0]);
		}
	}

	for(int i = 1; i < vec.size(); i++){
		if(res >= 1000)
			break;
		for(int j = i + 1; j < vec.size(); j++){
			if(vec[i] >= vec[j])
				res *= vec[i] - vec[j];
			else
				res *= vec[j] - vec[i];
			if(res >= 1000)
				break;
		}
	}

	printf("%lld\n", res % modulo);

	return 0;
}