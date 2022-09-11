class Solution {
public:
    int n, m;
    
    int bfs(pair <int, int> p, vector<vector<int>>& grid){
        queue <pair <int, int>> q;
        q.push(p);
        int nx, ny;
        pair <int, int> u;
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        
        grid[p.first][p.second] = 0;
        int ans = 1;
        bool flag = false;
        if(!(p.first >= 1 && p.first < n - 1 && p.second >= 1 && p.second < m - 1))
            flag = true;
        
        while(!q.empty()){
            u = q.front();
            
            for(int i = 0; i < 4; i++){
                nx = u.first + dx[i];
                ny = u.second + dy[i];
                
                if(nx >= 1 && nx < n - 1 && ny >= 1 && ny < m - 1 && grid[nx][ny]){
                    q.push({nx, ny});
                    grid[nx][ny] = 0;
                    ans++;
                }
                else if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny]){
                    flag = true;
                    q.push({nx, ny});
                    grid[nx][ny] = 0;
                }
            }
            
            q.pop();
        }
        
        if(flag)
            return 0;
        
        return ans;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int ans = 0;
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j])
                    ans += bfs({i, j}, grid);
        
        return ans;
    }
};