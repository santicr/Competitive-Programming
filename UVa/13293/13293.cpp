#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Person{
	string name;
	int points = 0;
};

typedef struct Person P;

string toLower(string str){
	string a = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string b = "abcdefghijklmnopqrstuvwxyz";
	string res = str;

	for(int i = 0; i < str.size(); i++){
		for(int j = 0; j < a.size(); j++){
			if(str[i] == a[j])
				res[i] = b[j];
		}
	}

	return res;
}

bool func(P p1, P p2){
	string a, b;
	a = toLower(p1.name);
	b = toLower(p2.name);
	if(p1.points != p2.points)
		return p1.points > p2.points;
	else
		return a < b;
}

vector <string> funcStr(string str){
	string temp;
	vector <string> res;
	int i, index = 0, count = 0, k;

	for(i = 0; i < str.size(); i++){
		if(count == 5){
			temp = str.substr(index, str.size() - index);
			res.push_back(temp);
			break;
		}
		if(str[i] == ';'){
			temp = str.substr(index, i - index);
			res.push_back(temp);
			index = i + 1;
			count++;
		}
	}

	return res;
}

int main(){
	int people, i, j, k, cases = 1;
	vector <string> vec;
	while(cin >> people){
		string str, temp;
		vector <string> res;
		vector <P> result;
		
		for(i = 0; i < people; i++){
			cin >> ws;
			getline(cin, str);
			vec.push_back(str);
			str.clear();
		}

		for(i = 0; i < people; i++){
			res = funcStr(vec[i]);
			P temp2;
			temp2.name = res[0];
			for(j = 1; j < res.size(); j++){
				for(k = 0; k < res[j].size(); k++){
					if(isdigit(res[j][k]) && k == res[j].size() - 1){
						if(res[j][k] == '1'){
							temp2.points += 2;
							break;
						}
					}
					if(isdigit(res[j][k])){
						if(res[j][k] == '1')
							temp2.points++;
					}
				}
			}
			result.push_back(temp2);
			temp2.points = 0;
		}

		res.clear();

		sort(result.begin(), result.end(), func);

		cout << "Case " << cases << ":" << endl;

		for(i = 0; i < result.size(); i++)
			cout << result[i].name << " " << result[i].points << endl;

		result.clear();
		vec.clear();
		cases++;
	}
	
	return 0;
}