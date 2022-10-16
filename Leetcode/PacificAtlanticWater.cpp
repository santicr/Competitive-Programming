typedef pair <int, int> P;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector <vector<int>> ans;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                    vector <vector <int>> vis(n, vector<int>(m, 0));
                    queue <P> q;
                    int x, y, nx, ny;
                    int dx[] = {1, 0, 0, -1};
                    int dy[] = {0, 1, -1, 0};
                    q.push(node);
                    vis[node.first][node.second] = 1;
                    int atlantic = 0, pacific = 0;

                    while(!q.empty()){
                        x = q.front().first;
                        y = q.front().second;
                        q.pop();
                        if(x == n - 1 || y == m - 1)
                            atlantic = 1;
                        if(x == 0 || y == 0)
                            pacific = 1;
                        if(pacific && atlantic)
                            break;

                        for(int i = 0; i < 4; i++){
                            nx = dx[i] + x;
                            ny = dy[i] + y;
                            if(nx >= 0 && ny >= 0 && nx < n && ny < m && heights[nx][ny] <= heights[x][y] && !vis[nx][ny]){
                                vis[nx][ny] = 1;
                                q.push({nx, ny});
                            }
                        }
                    }
                    
                    if(atlantic && pacific)
                        ans.push_back({i, j});
                }
            }
        }
        
        return ans;
    }
};