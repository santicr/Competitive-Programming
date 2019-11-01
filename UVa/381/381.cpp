#include <iostream>
#include <vector>

using namespace std;

struct Student{
	int number;
	vector <int> grades;
	int bonus;
	int absence;
};

typedef Student S;

int main(){
	int classes, students, tests, i, j, index = 0;
	vector <int> res;
	scanf("%d", &classes);
	if(index < 1){
		while(classes--){
			vector <S> s_grades;
			vector <int> class_mean;
			scanf("%d %d", &students, &tests);
			for(i = 0; i < students; i++){
				double average = 0;
				int grade;
				S temp;
				temp.number = i + 1;
				for(j = 0; j < tests; j++){
					scanf("%d", &grade);
					temp.grades.push_back(grade);
				}
				scanf("%d", &temp.bonus);
				scanf("%d", &temp.absence);

				if(temp.grades.size() > 2){
					auto it = temp.grades.begin();
					int temp2 = *it, pos = 0;
					for(j = 0; j < temp.grades.size(); j++){
						if(temp.grades[j] < temp2){
							temp2 = temp.grades[j];
							pos = j;
						}
					}
					temp.grades.erase(it + pos);
				}
				for(j = 0; j < temp.grades.size(); j++)
					average += temp.grades[j];

				average /= temp.grades.size();

				if(temp.bonus != 0 && temp.bonus != 1){
					if(temp.bonus % 2 == 0)
						average += (temp.bonus / 2) * 3;
					if(temp.bonus % 2 != 0)
						average += ((temp.bonus - 1) / 2) * 3;
				}
				if(temp.absence >= 4){
					
				}
			}

		}

		cout << "MAKING THE GRADE OUTPUT" << endl;

		cout << "END OF OUTPUT" << endl;
	}

	return 0;
}