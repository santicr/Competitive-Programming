#include <bits/stdc++.h>
#define MAXN 200002

using namespace std;

int n, tree[2 * MAXN];
vector <int> a(200002);

void build(int v, int l, int r) {
    if(l == r)
        tree[v] = a[l];
    else{
        int m = l + ((r - l) >> 1);
        build(v + 1, l, m);
        build(v + 2 * (m - l + 1), m + 1, r);
        tree[v] = tree[v + 1] + tree[v + 2 * (m - l + 1)];
    }
}

int sum(int v, int L, int R, int l, int r){
    int ans;
    if(l > r)
        ans = 0;
    else if(l == L && r == R)
        ans = tree[v];
    else{
        int m = L + ((R - L) >> 1);
        ans = sum(v + 1, L, m, l, min(r, m)) + sum(v + 2 * (m - L + 1), m + 1, R, max(l, m + 1), r);
    }
    return ans;
}

void update(int v, int L, int R, int pos, int val){
    if(L == R)
        tree[v] = val;
    else{
        int m = L + ((R - L) >> 1);

        if(pos <= m)
            update(v + 1, L, m, pos, val);
        else
            update(v + 2 * (m - L + 1), m + 1, R, pos, val);

        tree[v] = tree[v + 1] + tree[v + 2 * (m - L + 1)];
    }
}

int main(){
    int temp, temp2, casos = 1;
    string str;

    while(cin >> n && n){
        if(casos++ > 1)
            cout << endl;

        cout << "Case " << casos - 1 << ":" << endl;
        
        for(int i = 0; i < n; i++)
            cin >> a[i];

        build(0, 0, n - 1);
        cin >> str;

        while(str != "END"){
            cin >> temp >> temp2;
            if(str == "M")
                cout << sum(0, 0, n - 1, temp - 1, temp2 - 1) << endl;
            else
                update(0, 0, n - 1, temp - 1, temp2);
            cin >> str;
        }

    }

    return 0;
}