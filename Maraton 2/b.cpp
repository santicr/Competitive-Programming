#include <bits/stdc++.h>

using namespace std;

int func(vector <int> vec){
	int res1 = 0, res2 = 1;
	for(int i = 0; i < vec.size(); i++){
		res1 += vec[i];
		res2 *= vec[i];
	}

	if(res1 != 0 && res2 != 0)
		return true;
	return false;
}

int main(){
	int cases;
	cin >> cases;
	while(cases--){
		int size;
		cin >> size;
		vector <int> vec;
		for(int i = 0; i < size; i++){
			int temp;
			cin >> temp;
			vec.push_back(temp);
		}

		int res = 0;
		bool flag = false;

		if(func(vec)){
			printf("%d\n", res);
			break;
			flag = true;
		}
		if(!flag){
			for(int i = 0; i < vec.size(); i++){
				vec[i] += 1;
				if(func(vec)){
					printf("%d\n", res);
					break;
				}
				vec[i] -= 1;
				res++;
			}
		}

	}


	return 0;
}