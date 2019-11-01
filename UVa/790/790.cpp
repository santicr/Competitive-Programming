#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct SubTeam{
	string letter, status;
	int time = 0;
};
typedef struct SubTeam L;

struct Team{
	int team, time = 0, solved = 0;
	vector <L> vec;
};
typedef struct Team T;

bool function1(L a, L b){
	if(a.letter != b.letter)
		return a.letter < b.letter;
	else if(a.time != b.time)
		return a.time < b.time;
	return a.status < b.status;
}

bool function2(T a, T b){
	if(a.solved != b.solved)
		return a.solved > b.solved;
	else if(a.time != b.time)
		return a.time < b.time;
	return a.team < b.team;
}

vector <string> function(string str){ /* Returns a vector with each substring */
	vector <string> ans;
	int index = 0;
	for(int i = 0; i < str.size(); i++){
		if(str[i] == ' '){
			ans.push_back(str.substr(index, i - index));
			index = i + 1;
		}
		if(i == str.size() - 1)
			ans.push_back(str.substr(index, str.size() - index));
	}

	return ans;
}

void print(vector <T> teams){
	for(int i = 0; i < teams.size(); i++){
		cout << teams[i].team << " " << teams[i].time << endl;
		for(int j = 0; j < teams[i].vec.size(); j++){
			printf("%10s %10d %10s\n", teams[i].vec[j].letter.c_str(), teams[i].vec[j]
				.time, teams[i].vec[j].status.c_str());
		}
	}
}

T func(vector <string> vec){ /* Creates a temporal team */
	int hours = 0, minutes = 0;
	T team;
	L sub_team;
	team.team = atoi(vec[0].c_str());
	sub_team.letter = vec[1];
	sub_team.status = vec[3];
	for(int i = 0; i < vec[2].size(); i++){
		if(vec[2][i] == ':'){
			hours += atoi(vec[2].substr(0, i).c_str());
			minutes += atoi(vec[2].substr(i + 1, vec[2].size() - i).c_str());
		}
	}
	sub_team.time += minutes;
	sub_team.time += (hours * 60);
	team.vec.push_back(sub_team);

	return team;
}

int main(){
	int cases, other;
	cin >> cases;
	other = cases - 1;
	while(cases--){
		string str; /* String to read */
		bool paso = false, paso2 = false, paso3 = false;
		vector <string> ans, letters;
		T temp;
		vector <T> teams;
		if(other == cases){
			cin.ignore();
			cin.ignore();
		}
		while(getline(cin, str)){ /* Read all strings of each case */
			if(str.size() == 0)
				break;
			ans = function(str);
			for(int i = 0; i < letters.size(); i++) /* This is to not repeat */
				paso = (letters[i] == ans[1]) ? paso = true : paso;
			if(paso == false)
				letters.push_back(ans[1]);
			else
				paso = false;
			temp = func(ans);
			for(int i = 0; i < teams.size(); i++){ /* This is to not repeat */
				if(temp.team == teams[i].team){
					teams[i].vec.push_back(temp.vec[0]);
					paso2 = true;
				}
			}
			if(paso2 == false)
				teams.push_back(temp);
			else
				paso2 = false;
		}

		int flag = -1;
		for(int i = 0; i < teams.size(); i++){
			if(teams[i].team > flag)
				flag = teams[i].team;
		}

		T temp2;
		for(int i = 1; i <= flag; i++){
			temp2.team = i;
			for(int i = 0; i < teams.size(); i++){ /* This is to not repeat */
				if(temp2.team == teams[i].team)
					paso3 = true;
			}
			if(paso3 == false)
				teams.push_back(temp2);
			else
				paso3 = false;
		}

		for(int i = 0; i < teams.size(); i++)
			sort(teams[i].vec.begin(), teams[i].vec.end(), function1);

		sort(letters.begin(), letters.end());

		for(int i = 0; i < letters.size(); i++){
			for(int j = 0; j < teams.size(); j++){
				int count = 0;
				for(int k = 0; k < teams[j].vec.size(); k++){
					if(teams[j].vec[k].status == "N" && teams[j].vec[k].letter == letters[i]
						&& teams[j].vec[k].letter <= "G" && teams[j].vec[k].letter >= "A")
						count += 20;
					else if(teams[j].vec[k].status == "Y" && teams[j].vec[k].letter == letters[i]
						&& teams[j].vec[k].letter <= "G" && teams[j].vec[k].letter >= "A"){
						teams[j].time += teams[j].vec[k].time;
						teams[j].time += count;
						teams[j].solved++;
						break;
					}
				}
			}
		}


		sort(teams.begin(), teams.end(), function2);

		printf("%4s%5s%11s%5s\n", "RANK", "TEAM", "PRO/SOLVED", "TIME");
		int rank = 0;
		for(int i = 0; i < teams.size(); i++){
			if(i == 0 && teams[i].solved > 0){
				printf("%4d%5d%5d%11d\n", i + 1, teams[i].team, teams[i].solved,
				teams[i].time);
			}
			if(i == 0 && teams[i].solved == 0)
				printf("%4d%5d\n", i + 1, teams[i].team);
			if(i > 0 && teams[i].solved == teams[i - 1].solved && teams[i].time ==
				teams[i - 1].time && teams[i].solved > 0){
				printf("%4d%5d%5d%11d\n", rank + 1, teams[i].team, teams[i].solved,
				teams[i].time);
			}
			if(i > 0 && teams[i].solved == teams[i - 1].solved && teams[i].time ==
				teams[i - 1].time && teams[i].solved == 0){
				printf("%4d%5d\n", rank + 1, teams[i].team);
			}
			if(i > 0 && teams[i].solved != teams[i - 1].solved && teams[i].time !=
				teams[i - 1].time && teams[i].solved > 0){
				printf("%4d%5d%5d%11d\n", i + 1, teams[i].team, teams[i].solved,
				teams[i].time);
				rank = i;
			}
			if(i > 0 && teams[i].solved != teams[i - 1].solved && teams[i].time !=
				teams[i - 1].time && teams[i].solved == 0){
				printf("%4d%5d\n", i + 1, teams[i].team);
				rank = i;
			}
			if(i > 0 && teams[i].solved == teams[i - 1].solved && teams[i].time !=
				teams[i - 1].time && teams[i].solved > 0){
				printf("%4d%5d%5d%11d\n", i + 1, teams[i].team, teams[i].solved,
				teams[i].time);
				rank = i;
			}
			if(i > 0 && teams[i].solved == teams[i - 1].solved && teams[i].time !=
				teams[i - 1].time && teams[i].solved == 0){
				printf("%4d%5d\n", i + 1, teams[i].team);
				rank = i;
			}
			if(i > 0 && teams[i].solved != teams[i - 1].solved && teams[i].time ==
				teams[i - 1].time && teams[i].solved > 0){
				printf("%4d%5d%5d%11d\n", i + 1, teams[i].team, teams[i].solved,
				teams[i].time);
				rank = i;
			}
			if(i > 0 && teams[i].solved != teams[i - 1].solved && teams[i].time ==
				teams[i - 1].time && teams[i].solved == 0){
				printf("%4d%5d\n", i + 1, teams[i].team);
				rank = i;
			}
		}
		if(cases != 0)
			printf("\n");
	}



	return 0;
}