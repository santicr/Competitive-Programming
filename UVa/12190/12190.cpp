#include <bits/stdc++.h>

using namespace std;

int tm1, tm2;

void solve1(){
	int total = 0;
	if(tm1 > 1000000){
		total += ((tm1 - 1000000) * 7);
		tm1 -= (tm1 - 1000000);
	}
	if(tm1 > 10000){
		total += ((tm1 - 10000) * 5);
		tm1 -= (tm1 - 10000);
	}
	if(tm1 > 100){
		total += ((tm1 - 100) * 3);
		tm1 -= (tm1 - 100);
	}
	if(tm1 > 0){
		total += (tm1 * 2);
	}

	tm1 = total;
}

void solve2(){
	int total = 0;
	if(tm2 > 1000000){
		total += ((tm2 - 1000000) * 7);
		tm2 -= (tm2 - 1000000);
	}
	if(tm2 > 10000){
		total += ((tm2 - 10000) * 5);
		tm2 -= (tm2 - 10000);
	}
	if(tm2 > 100){
		total += ((tm2 - 100) * 3);
		tm2 -= (tm2 - 100);
	}
	if(tm2 > 0){
		total += (tm2 * 2);
	}

	tm2 = total;
}

int main(){
	int A, B = 300, total;
	int m, n, s1, s2;
	bool t1, t2, t3, t4;

	cin >> A >> B;
	while(A != 0 && B != 0){
		t1 = false;
		t2 = false;
		t3 = false;
		total = 0, n = 0;

		if(A > 200){
			total += 200;
			n += 100;
			t1 = true;
		}
		if(A > 29900){
			total += 29700;
			n += 9900;
			t2 = true;
		}
		if(A > 4979900){
			total += 4950000;
			n += 990000;
			t3 = true;
		}

		if(t3 == true){
			n += (A - total) / 7;
		}
		else if(t2 == true){
			n += (A - total) / 5;
		}
		else if(t1 == true){
			n += (A - total) / 3;	
		}
		else{
			n += (A / 2);
		}

		m = n;
		int low = 0, high = n / 2;

		while(low + 1 < high && abs(tm1 - tm2) != B){
			int mid = (low + high) / 2;
			tm1 = mid;
			tm2 = m - tm1;
			solve1();
			solve2();
			if(abs(tm1 - tm2) > B){
				low = mid;
			}
			else
				high = mid;
		}
		tm1 = high;
		solve1();

		cout << tm1 << endl;
		tm1 = -1, tm2 = -1;

		cin >> A >> B;
	}

	return 0;
}