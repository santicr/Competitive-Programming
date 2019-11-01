#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

struct Team{
	int points = 0, goal_dif = 0, scored_goals = 0, played = 0, suffered = 0;
	string name;

};

typedef struct Team T;

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

bool funct(T a, T b){
	if(a.points != b.points)
		return a.points > b.points;
	else if(a.goal_dif != b.goal_dif)
		return a.goal_dif > b.goal_dif;
	else if(a.scored_goals != b.scored_goals)
		return a.scored_goals > b.scored_goals;
	else
		return toLower(a.name) < toLower(b.name);
}

void func(string a, vector <T> *b){
	vector <string> res;
	string temp;
	int indice = 0, j = 0;
	for(int i = 0; i < a.size(); i++){
		if(a[i] == ' '){
			temp = a.substr(indice, i - indice);
			indice = i + 1;
			res.push_back(temp);
		}
		if(i == a.size() - 1){
			temp = a.substr(indice, a.size() - indice);
			res.push_back(temp);
		}
	}

	vector <string> :: iterator it = res.begin();
	it += 2;
	res.erase(it);

	for(int i = 0; i < b -> size(); i++){
		if(b -> at(i).name == res[0]){
			if(atoi(res[1].c_str()) > atoi(res[2].c_str()))
				b -> at(i).points += 3;
			if(atoi(res[1].c_str()) == atoi(res[2].c_str()))
				b -> at(i).points += 1;
			b -> at(i).goal_dif -= atoi(res[2].c_str());
			b -> at(i).goal_dif += atoi(res[1].c_str());
			b -> at(i).scored_goals += atoi(res[1].c_str());
			b -> at(i).played++;
			b -> at(i).suffered += atoi(res[2].c_str());
			break;
		}
	}
	for(int i = 0; i < b -> size(); i++){
		if(b -> at(i).name == res[3]){
			if(atoi(res[2].c_str()) > atoi(res[1].c_str()))
				b -> at(i).points += 3;
			if(atoi(res[1].c_str()) == atoi(res[2].c_str()))
				b -> at(i).points += 1;
			b -> at(i).goal_dif -= atoi(res[1].c_str());
			b -> at(i).goal_dif += atoi(res[2].c_str());
			b -> at(i).scored_goals += atoi(res[2].c_str());
			b -> at(i).played++;
			b -> at(i).suffered += atoi(res[1].c_str());
			break;
		}
	}

} 

int main(){
	int num_teams, num_matches, indice = 0;
	scanf("%d %d", &num_teams, &num_matches);
	while(num_teams != 0){
		if(indice == 0)
			indice++;
		else
			printf("\n");
		vector <T> teams;
		vector <string> matches;
		T team_temp; 
		string match_temp;
		for(int i = 0; i < num_teams; i++){
			cin >> team_temp.name;
			teams.push_back(team_temp);
		}

		for(int i = 0; i < num_matches; i++){
			cin >> ws;
			getline(cin, match_temp);
			func(match_temp, &teams);
		}

		sort(teams.begin(), teams.end(), funct);

		for(int i = 0; i < teams.size(); i++){
			if(i > 0 && teams[i].points == teams[i - 1].points && 
				teams[i].goal_dif == teams[i - 1].goal_dif && teams[i].scored_goals
				== teams[i - 1].scored_goals){
				printf("%19s%4d%4d%4d%4d%4d", teams[i].name.c_str(), 
					teams[i].points, teams[i].played, teams[i].scored_goals, 
					teams[i].suffered, teams[i].goal_dif);
				if(teams[i].played > 0){
					double e = teams[i].points, f = teams[i].played * 3;
					double r = e / f * 100;
					printf("%7.2f\n", r);
				}
				else
					printf("%7s\n", "N/A");
			}
			else{
				printf("%2d.%16s%4d%4d%4d%4d%4d", i + 1, teams[i].name.c_str(), 
					teams[i].points, teams[i].played, teams[i].scored_goals, 
					teams[i].suffered, teams[i].goal_dif);
				if(teams[i].played > 0){
					double e = teams[i].points, f = teams[i].played * 3;
					double r = e / f * 100;
					printf("%7.2f\n", r);
				}
				else
					printf("%7s\n", "N/A");
			}
		}
		scanf("%d %d", &num_teams, &num_matches);
	}


	return 0;
}