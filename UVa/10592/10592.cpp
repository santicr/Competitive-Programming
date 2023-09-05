#include <bits/stdc++.h>

using namespace std;

int n, fighter_pos_num = 0;

int mini_bfs (int x, int y, map <pair <int, int>, int> &vis, vector <string> &mat) {
    int dx[] = {1, 0, 0, -1};
    int dy[] = {0, -1, 1, 0};
    int nx, ny;
    queue <pair <int, int>> q;
    map <char, int> is_present;

    q.push({x, y});

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;

        for (int i = 0; i < 4; i++) {
            nx = dx[i] + x;
            ny = dy[i] + y;

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[{nx, ny}] && (mat[nx][ny] == 'B' || mat[nx][ny] == 'P')) {
                is_present[mat[nx][ny]] = 1;
                q.push({nx, ny});
                vis[{nx, ny}] = 1;
            }
        }

        q.pop();
    }

    if (is_present['B'] && is_present['P'])
        fighter_pos_num += 2;

    return is_present['B'] && is_present['P'];
}

pair <int, int> bfs (int x, int y, map <pair <int, int>, int> &vis, vector <string> &mat) {
    int dx[] = {1, 0, 0, -1};
    int dy[] = {0, -1, 1, 0};
    int nx, ny;
    queue <pair <int, int>> q;
    int freedom_fighters = 0;
    int enemy_groups = 0;

    q.push({x, y});

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;

        for (int i = 0; i < 4; i++) {
            nx = dx[i] + x;
            ny = dy[i] + y;

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !vis[{nx, ny}] && (mat[nx][ny] == '*' || mat[nx][ny] == 'B' || mat[nx][ny] == 'P')) {
                vis[{nx, ny}] = 1;
                
                if (mat[nx][ny] == 'B') {
                    int res = mini_bfs(nx, ny, vis, mat);
                    if (res){
                        freedom_fighters += res;
                        enemy_groups += res;
                    }
                    else {
                        freedom_fighters++;
                    }
                }
                else if (mat[nx][ny] == 'P') {
                    int res = mini_bfs (nx, ny, vis, mat);
                    if (res) {
                        freedom_fighters += res;
                        enemy_groups += res;
                    }
                    else {
                        enemy_groups++;
                    }
                }
                else
                    q.push({nx, ny});
            }
        }

        q.pop();
    }

    return make_pair (freedom_fighters, enemy_groups);
}

void solve(vector <string> &mat) {
    map <pair <int, int>, int> vis;
    map <int, pair <int, int> > ans;
    int sectors = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c = mat[i][j];
            if (c == '*' && !vis[{i, j}]) {
                vis[{i, j}] = 1;
                pair <int, int> sector_ans = bfs(i, j, vis, mat);
                sectors++;
                ans[sectors] = sector_ans;
            }
        }
    }

    for (int i = 0; i < sectors; i++)
        printf("Sector #%d: contain %d freedom fighter group(s) & %d enemy group(s)\n", i + 1, ans[i + 1].first, ans[i + 1].second);
    printf("Total %d group(s) are in fighting position.\n\n", fighter_pos_num);

    return;
}

int main() {
    string line;
    vector <string> mat;

    while(cin >> n, n) {
        for (int i = 0; i < n; i++) {
            cin >> line;
            mat.push_back(line);
        }

        solve(mat);
        fighter_pos_num = 0;
        mat.clear();

    }

    return 0;
}