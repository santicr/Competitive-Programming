#include <bits/stdc++.h>

using namespace std;

int main(){
	int ops, x, y;
	map <int, string> res = {{0, "stack"}, {1, "queue"}, {2, "priority queue"}};

	while(cin >> ops){
		stack <int> s;
		queue <int> q;
		priority_queue <int> pq;
		int possi[] = {1, 1, 1};
		vector <int> vec;

		while(ops--){
			cin >> x >> y;

			if(x == 1){
				pq.push(y);
				q.push(y);
				s.push(y);
			}
			else if(x == 2){
				if(!pq.empty() && y != pq.top())
					possi[2] = 0;
				
				else if(pq.empty())
					possi[2] = 0;
				
				if(!q.empty() && y != q.front())
					possi[1] = 0;
				
				else if(q.empty())
					possi[1] = 0;
				
				if(!s.empty() && y != s.top())
					possi[0] = 0;
				
				else if(s.empty())
					possi[0] = 0;

				if(!q.empty()) q.pop();
				if(!pq.empty()) pq.pop();
				if(!s.empty()) s.pop();
				
			}
		}
		
		for(int i = 0; i < 3; i++){
			if(possi[i])
				vec.push_back(i);
		}

		if(vec.size() == 1)
			cout << res[vec[0]] << endl;
		else if(vec.size() >= 2)
			cout << "not sure" << endl;
		else
			cout << "impossible" << endl;

	}

	return 0;
}