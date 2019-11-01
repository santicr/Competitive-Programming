#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int modulo;

int mod(int n){
	return (n % modulo);
}

int oddOrEven(int n){
	if(n % 2 != 0)
		return 1;
	return 0;
}

bool func(int a, int b){
	if(mod(a) != mod(b))
		return mod(a) < mod(b);
	else if(oddOrEven(a) != oddOrEven(b))
		return oddOrEven(a) > oddOrEven(b);
	else if(oddOrEven(a) == 0 && oddOrEven(b) == 0)
		return a < b;
	return a > b;
}

int main(){
	int cases;
	scanf("%d %d", &cases, &modulo);
	while(cases != 0 && modulo != 0){
		vector <int> numbers;
		int num, i;
		for(i = 0; i < cases; i++){
			cin >> num;
			numbers.push_back(num);
		}
		cout << cases << " " << modulo << endl;
		sort(numbers.begin(), numbers.end(), func);

		for(i = 0; i < numbers.size(); i++)
			cout << numbers[i] << endl;

		scanf("%d %d", &cases, &modulo);
	}
	printf("%d %d\n", cases, modulo);

	return 0;
}