#include <iostream>
#include <vector>

using namespace std;

bool backtrack(vector <int> vec, int index, int n, int acum){
	if(acum == n)
		return true;
	else if(acum > n)
		return false;
	else if(index == vec.size())
		return false;
	return (backtrack(vec, index + 1, n, acum) || (backtrack(vec, index + 1, n, vec[index] + acum)));
}

int main(){
	int cases;

	cin >> cases;

	while(cases--){
		vector <int> vec;
		int n, size, temp;

		cin >> n >> size;

		for(int i = 0; i < size; i++){
			cin >> temp;
			vec.push_back(temp);
		}

		if(backtrack(vec, 0, n, 0))
			printf("YES\n");
		else
			printf("NO\n");

	}


	return 0;
}