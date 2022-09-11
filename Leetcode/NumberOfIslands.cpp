int n, m;

class Solution {
public:
    void bfs(pair <int, int> p, vector <vector<char>> &grid){
        pair <int, int> u;
        queue <pair <int, int>> q;
        int dx[] = {1, 0, 0, -1};
        int dy[] = {0, 1, -1, 0};
        int nx, ny;
        
        q.push(p);
        grid[p.first][p.second] = '0';
        
        while(!q.empty()){
            u = q.front();
            
            for(int i = 0; i < 4; i++){
                nx = dx[i] + u.first;
                ny = dy[i] + u.second;
                
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '1'){
                    grid[nx][ny] = '0';
                    q.push({nx, ny});
                }
            }
            
            q.pop();
        }
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    bfs({i, j}, grid);
                    ans++;
                }
            }
        }
        
        return ans;
    }
};