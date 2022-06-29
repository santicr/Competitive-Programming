class Solution {
public:
    int bfs(vector<vector<int>>& grid, pair <int, int> nodo){
        int dx[] = {0, 1, -1, 0};
        int dy[] = {1, 0, 0, -1};
        int nx, ny, n, m, ans;
        pair <int, int> u;
        queue <pair <int, int>> q;
        
        grid[nodo.first][nodo.second] = 0;
        n = grid.size();
        m = grid[0].size();
        q.push(nodo);
        ans = 1;
        
        while(!q.empty()){
            u = q.front();
            
            for(int i = 0; i < 4; i++){
                nx = dx[i] + u.first;
                ny = dy[i] + u.second;
                
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1){
                    q.push({nx, ny});
                    grid[nx][ny] = 0;
                    ans++;
                }
            }
            
            q.pop();
        }
        
        return ans;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j] == 1)
                    ans = max(bfs(grid, {i, j}), ans);
        
        return ans;
    }
};