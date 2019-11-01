#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct A{
	int a;
	int pos;
};

void print(vector <int> vec){
	int j;
	for(j = 0; j < vec.size(); j++){
		printf("%d ", vec[j]);
	}
	printf("\n");
}

void print2(vector <A> vec){
	int j;
	for(j = 0; j < vec.size(); j++){
		printf("%d -> pos %d ", vec[j].a, vec[j].pos);
	}
	printf("\n");
}

int main(){
	int cases, i, j, k;
	cin >> cases;
	for(i = 0; i < cases; i++){
		int available, needed, N;
		vector <A> avail;
		vector <int> need;
		cin >> N;
		for(j = 0; j < N; j++){
			A temp;
			cin >> available;
			temp.a = available;
			temp.pos = j;
			avail.push_back(temp);
		}
		for(j = 0; j < N; j++){
			cin >> needed;
			need.push_back(needed);
		}
		bool paso = false;
		while(N--){
			int temp = 0, res;
			for(j = 0; j < need.size(); j++){
				temp += avail[j].a;
				temp -= need[j];
				if(temp < 0)
					break;
				else if(j == need.size() - 1 && temp >= 0){
					res = avail[0].pos;
					printf("Case %d: Possible from station %d\n", i + 1, 
						res + 1);
					paso = true;
					break;
				}
			}
			need.push_back(need[0]);
			need.erase(need.begin());
			avail.push_back(avail[0]);
			avail.erase(avail.begin());
			if(paso == true)
				break;
		}
		if(paso == false)
			printf("Case %d: Not possible\n", i + 1);
	}
	return 0;
}