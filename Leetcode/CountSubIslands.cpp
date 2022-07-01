class Solution {
public:
    typedef pair <int, int> p;
    int n, m;
    int vis[502][502];
    
    void bfs(p nodo, vector<vector<int>>& grid){
        queue <p> q;
        p u;
        int dx[] = {1, 0, 0, -1};
        int dy[] = {0, 1, -1, 0};
        int nx, ny;
        q.push(nodo);
        vis[nodo.first][nodo.second] = 1;
        
        while(!q.empty()){
            u = q.front();
            
            for(int i = 0; i < 4; i++){
                nx = dx[i] + u.first;
                ny = dy[i] + u.second;
                
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && grid[nx][ny]){
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
            
            q.pop();
        }
    }
    
    int bfs2(p nodo, vector<vector<int>>& grid){
        queue <p> q;
        p u;
        int dx[] = {1, 0, 0, -1};
        int dy[] = {0, 1, -1, 0};
        int nx, ny, ans = 1;
        
        bool flag = false;
        grid[nodo.first][nodo.second] = 0;
        q.push(nodo);
        if(!vis[nodo.first][nodo.second])
            flag = true;
        
        while(!q.empty()){
            u = q.front();
            
            for(int i = 0; i < 4; i++){
                nx = dx[i] + u.first;
                ny = dy[i] + u.second;
                
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && vis[nx][ny] && grid[nx][ny]){
                    q.push({nx, ny});
                    grid[nx][ny] = 0;
                }
                else if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && grid[nx][ny]){
                    q.push({nx, ny});
                    grid[nx][ny] = 0;
                    flag = true;
                }
            }
            
            q.pop();
        }
        
        if(flag)
            ans = 0;
        return ans;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        n = grid1.size(), m = grid1[0].size();
        int ans = 0;
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(!vis[i][j] && grid1[i][j])
                    bfs({i, j}, grid1);        
        
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid2[i][j])
                    ans += bfs2({i, j}, grid2);
        
        return ans;
    }
};