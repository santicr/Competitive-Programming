#include <iostream>
#include <vector>

using namespace std;

struct P{
	int num;
	int pos;
};

bool IsIn(vector <P> vec, int num){
	for(auto it = vec.begin(); it != vec.end(); it++){
		if(num == it -> num)
			return true;
	}
	return false;
}

bool IsQueue(vector <P> vec, int num){
	for(auto it = vec.begin(); it != vec.end(); it++){
		if(num == it -> num && 0 == it -> pos)
			return true;
	}
	return false;
}

bool IsStack(vector <P> vec, int num){
	for(auto it = vec.begin(); it != vec.end(); it++){
		if(num == it -> num && (vec.size() - 1) == it -> pos)
			return true;
	}
	return false;
}

int main(){
	int n;
	while(cin >> n){
		vector <P> vec;
		int pos = 0;
		while(n--){
			int num1, num2;
			scanf("%d %d", &num1, &num2);
			if(num1 == 1){
				P temp;
				temp.num = num2;
				temp.pos = pos;
				vec.push_back(temp);
				pos++;
			}
			if(num1 == 2){
				if(!(IsIn(vec, num2))){
					printf("impossible\n");
					break;
				}

			}
		}
	}

	return 0;
}