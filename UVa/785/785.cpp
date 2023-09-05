#include <bits/stdc++.h>

using namespace std;

bool is_finish (string line) {
    map <char, int> counter;

    for (int i = 0; i < line.size(); i++) {
        char c = line[i];
        counter[c]++;
    }

    return counter.size() == 1 && counter['_'];
}

void bfs (vector <string> &mat, char icon, int x, int y, char border, map <pair <int, int>, int> &vis) {
    int dx[] = {0, 1, -1, 0};
    int dy[] = {1, 0, 0, -1};
    int n = mat.size();
    int m = 80;
    queue <pair <int, int>> q;
    int nx, ny;

    q.push({x, y});

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;

        for (int i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && (mat[nx][ny] == ' ' || mat[nx][ny] == icon) && !vis[{nx, ny}]) {
                mat[nx][ny] = icon;
                q.push({nx, ny});
                vis[{nx, ny}] = 1;
            }
        }

        q.pop();
    }
}

void solve (vector <string> &mat, string line) {
    map <char, int> char_counter;
    map <pair <int, int>, int> vis;
    char border;
    int max_number = -1;

    for (int i = 0; i < mat.size(); i++){
        for (int j = 0; j < mat[i].size(); j++){
            char s = mat[i][j];
            if (s != ' ')
                char_counter[s]++;
        }
    }

    for (auto it = char_counter.begin(); it != char_counter.end(); it++) {
        if (max_number < it -> second) {
            max_number = it -> second;
            border = it -> first;
        }
    }

    for (int i = 0; i < mat.size(); i++){
        for (int j = 0; j < mat[i].size(); j++){
            char s = mat[i][j];
            if (s != border && s != ' ' && !vis[{i, j}]){
                vis[{i, j}] = 1;
                bfs(mat, s, i, j, border, vis);
            }
        }
    }

    for (int i = 0; i < mat.size(); i++)
        cout << mat[i] << endl;

    cout << line << endl;

    return;
}

int main() {
    vector <string> mat;
    string line;

    while (getline(cin, line)) {
        if (is_finish(line)){
            solve(mat, line);
            mat.clear();
        }
        else {
            mat.push_back(line);
        }
    }

    return 0;
}