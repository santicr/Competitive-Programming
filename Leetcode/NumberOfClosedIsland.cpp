class Solution {
public:
    int bfs(vector<vector<int>>& grid, pair <int, int> nodo){
        int dx[] = {1, 0, 0, -1};
        int dy[] = {0, 1, -1, 0};
        queue <pair <int, int>> q;
        int nx, ny, n, m, ans;
        pair <int, int> u;
        
        n = grid.size();
        m = grid[0].size();
        q.push(nodo);
        grid[nodo.first][nodo.second] = 1;
        
        if(nodo.first >= 1 && nodo.first < n - 1 && nodo.second >= 1 && nodo.second < m - 1)
            ans = 1;
        else
            ans = 0;
        
        while(!q.empty()){
            u = q.front();
            
            for(int i = 0; i < 4; i++){
                nx = dx[i] + u.first;
                ny = dy[i] + u.second;
                
                if(nx >= 1 && nx < n - 1 && ny >= 1 && ny < m - 1 && grid[nx][ny] == 0){
                    q.push({nx, ny});
                    grid[nx][ny] = 1;
                }
                else if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 0){
                    q.push({nx, ny});
                    grid[nx][ny] = 1;
                    ans = 0;
                }
            }
            
            q.pop();
        }
        
        return ans;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans;
        ans = 0;
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j] == 0)
                    ans += bfs(grid, {i, j});
        
        return ans;
    }
};