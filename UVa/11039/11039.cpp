#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct P{
	int num;
	char sign;
};

bool func(P a, P b){
	return a.num > b.num;
}

int main(){
	int cases, i, j;
	cin >> cases;
	while(cases--){
		vector <P> vec;
		int floors, number;
		P temp;
		cin >> floors;
		for(j = 0; j < floors; j++){
			cin >> number;
			if(number <= 0){
				temp.sign = '-';
				temp.num = -number;
				vec.push_back(temp);
			}
			else{
				temp.sign = '+';
				temp.num = number;
				vec.push_back(temp);
			}
		}

		sort(vec.begin(), vec.end(), func);

		int res = 0;
		char s;
		if(vec.size() > 0){
			res++;
			s = vec[0].sign;
		}
		for(i = 0; i < vec.size(); i++){
			if(vec[i].sign != s){
				res++;
				s = vec[i].sign;
			}
		}

		printf("%d\n", res);
	}


	return 0;
}