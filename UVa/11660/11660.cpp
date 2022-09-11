#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct P{
	char num;
	int veces = 0;
};

int min(int a, int b){
	if(a < b)
		return a;
	else
		return b;
}

int max(int a, int b){
	if(a > b)
		return a;
	else
		return b;
}

int main(){
	string str, str2, str3;
	while(cin >> str >> str2 >> str3){
		if(str == "0" && str2 == "0" && str3 == "0")
			break;
		int j = atoi(str2.c_str()) - 1;
		char res = str[0];
		while(j--){
			P temp;
			temp.num = str[0];
			vector <P> vec;
			for(int i = 0; i < min(str.size(), (atoi(str3.c_str()) + 4)); i++){
				if(temp.num == str[i])
					temp.veces++;
				else if(str[i] != temp.num){
					vec.push_back(temp);
					temp.num = str[i];
					temp.veces = 1;
				}
			}
			vec.push_back(temp);
			str.clear();
			char c;
			for(int i = 0; i < min(vec.size(), atoi(str3.c_str()) + 4); i++){
				c = vec[i].veces + '0';
				str.push_back(c);
				str.push_back(vec[i].num);
			}
		}
		res = str[atoi(str3.c_str()) - 1];
		cout << res << endl;
	}

	return 0;
}