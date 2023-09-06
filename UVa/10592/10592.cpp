#include <bits/stdc++.h>

using namespace std;

int n;
vector <string> mat;
map <pair <int, int>, int> vis;

int fighter_pos = 0;
int b_group = 0;
int p_group = 0;

void mini_bfs(int x, int y, map <pair <int, int>, int> &vis) {
    int dx[] = {1, 0, -1, 0}, nx;
    int dy[] = {0, 1, 0, -1}, ny;
    queue <pair <int, int>> q;
    char init = mat[x][y];

    vis[make_pair(x, y)] = 1;
    q.push(make_pair(x, y));
    int b = 0;
    int p = 0;

    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;

        for (int i = 0; i < 4; i++) {
            nx = dx[i] + x;
            ny = dy[i] + y;

            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                char s = mat[nx][ny];

                if (init == 'B' && s == 'P'){
                    p = 1;
                    b = 1;
                }
                
                if (s == 'B' && !vis[make_pair(nx, ny)]) {
                    vis[make_pair(nx, ny)] = 1;
                    b = 1;
                    q.push(make_pair(nx, ny));
                }
                else if (s == 'P' && !vis[make_pair(nx, ny)]) {
                    vis[make_pair(nx, ny)] = 1;
                    p = 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }

        q.pop();
    }
    if (init == 'B')
        fighter_pos = p && b ? fighter_pos + 1: fighter_pos;
}

void bfs(int x, int y) {
    int dx[] = {1, 0, -1, 0}, nx;
    int dy[] = {0, 1, 0, -1}, ny;
    queue <pair <int, int>> q;
    map <pair <int, int>, int> vis_b;
    map <pair <int, int>, int> vis_p;
    vector <pair <int, int>> b_v, p_v;
    q.push(make_pair(x, y));

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;

        for (int i = 0; i < 4; i++) {
            nx = dx[i] + x;
            ny = dy[i] + y;

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[make_pair(nx, ny)]) {
                char s = mat[nx][ny];
                vis[make_pair(nx, ny)] = 1;

                if (s == 'B') {
                    b_v.push_back(make_pair(nx, ny));
                    q.push(make_pair(nx, ny));
                }

                else if (s == 'P') {
                    p_v.push_back(make_pair(nx, ny));
                    q.push(make_pair(nx, ny));
                }
                else if (s == '*') {
                    q.push(make_pair(nx, ny));
                }
            }
        }
        q.pop();
    }

    for (int i = 0; i < b_v.size(); i++) {
        if (!vis_b[b_v[i]]) {
            vis_b[b_v[i]] = 1;
            b_group++;
            mini_bfs(b_v[i].first, b_v[i].second, vis_b);
        }
    }

    for (int i = 0; i < p_v.size(); i++) {
        if (!vis_p[p_v[i]]) {
            vis_p[p_v[i]] = 1;
            p_group++;
            mini_bfs(p_v[i].first, p_v[i].second, vis_p);
        }
    }

}

void solve() {
    int sector = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char s = mat[i][j];
            if (s == '*' and !vis[make_pair(i, j)]) {
                vis[make_pair(i, j)] = 1;
                bfs(i, j);
                printf("Sector #%d: contain %d freedom fighter group(s) & %d enemy group(s)\n", ++sector, b_group, p_group);
                b_group = 0;
                p_group = 0;
            }
        }
    }

    printf("Total %d group(s) are in fighting position.\n\n", fighter_pos * 2);
}

int main(){
    string line;

    while (cin >> n, n) {
        for (int i = 0; i < n; i++){
            cin >> line;
            mat.push_back(line);
        }
        solve();
        mat = vector <string> ();
        vis = map <pair <int, int>, int> ();

        fighter_pos = 0;
        b_group = 0;
        p_group = 0;
    }

    return 0;
}