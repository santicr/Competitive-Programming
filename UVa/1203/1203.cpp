#include <bits/stdc++.h>

using namespace std;

struct P{
	int time, reg;
};

int main(){
	string str;
	bool flag = false;
	map <int, int> mapa;
	cin >> str;
	while(true){
		int reg, time;
		if(str != "#"){
			cin >> reg >> time;
			mapa[reg] = time;
		}
		else{
			int tasks, res = 0;
			cin >> tasks;
			for(int i = 1; i <= 3000; i++){
				for(auto it = mapa.begin(); it != mapa.end(); it++){
					if(i % it -> second == 0){
						res++;
						cout << it -> first << endl;
						if(res == tasks){
							flag = true;
							break;
						}
					}
					if(flag)
						break;
				}
				if(flag)
					break;
			}
			if(res == tasks){
				flag = true;
				break;
			}
		}
		if(flag)
			break;
		cin >> str;
	}

	return 0;
}