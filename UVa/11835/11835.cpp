#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pair{
	int pos;
	int pilot;
	int points = 0;
};
typedef struct Pair P;

bool func(P a, P b){
	if(a.points != b.points)
		return a.points > b.points;
	else
		return a.pilot < b.pilot;
}

int main(){
	int races, pilots, i, j, score_sys, all_pos, pos_point, k, l, m;
	vector <P> race_pos;
	vector <int> points_vec;
	vector <P> pilots_vec;
	vector <vector <P>> all_races;
	scanf("%d %d", &races, &pilots);
	while(races != 0 && pilots != 0){
		for(i = 0; i < races; i++){
			for(j = 0; j < pilots; j++){
				P temp;
				scanf("%d", &temp.pos);
				temp.pilot = j + 1;
				race_pos.push_back(temp);
				if(i == 0)
					pilots_vec.push_back(temp);
			}
			all_races.push_back(race_pos);

			race_pos.clear();
		}

		scanf("%d", &score_sys);

		for(i = 0; i < score_sys; i++){
			scanf("%d", &all_pos);
			for(j = 0; j < all_pos; j++){
				scanf("%d", &pos_point);
				points_vec.push_back(pos_point);
			}

			for(j = 0; j < all_races.size(); j++){
				for(k = 0; k < all_races[j].size(); k++){
					for(l = 0; l < all_pos; l++){
						if(all_races[j][k].pos == l + 1){
							for(m = 0; m < pilots_vec.size(); m++){
								if(all_races[j][k].pilot == pilots_vec[m].pilot){
									pilots_vec[m].points += points_vec[l];
								}
							}
						}
					}
				}
			}

			points_vec.clear();
			sort(pilots_vec.begin(), pilots_vec.end(), func);
			int temporal = pilots_vec[0].points;
			
			for(j = 0; j < pilots_vec.size(); j++){
				if(pilots_vec[j].points == temporal && j == 0)
					printf("%d", pilots_vec[j].pilot);
				else if(pilots_vec[j].points == temporal && j > 0)
					printf(" %d", pilots_vec[j].pilot);
			}

			printf("\n");

			for(j = 0; j < pilots_vec.size(); j++)
				pilots_vec[j].points = 0;

		}
		all_races.clear();
		pilots_vec.clear();
		scanf("%d %d", &races, &pilots);
	}

	return 0;
}