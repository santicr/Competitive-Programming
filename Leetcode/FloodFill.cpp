class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue <pair <int, int>> q;
        int vis[52][52], nx, ny;
        pair <int, int> u, v;
        int dx[] = {1, 0, 0, -1};
        int dy[] = {0, 1, -1, 0};
        int n = image.size(), m = image[0].size();
        int cl = image[sr][sc];
        image[sr][sc] = color;
    
        q.push({sr, sc});
        
        for(int i = 0; i < 52; i++)
            for(int j = 0; j < 52; j++)
                vis[i][j] = 0;
        
        vis[sr][sc] = 1;
        
        while(!q.empty()){
            u = q.front();
            
            for(int i = 0; i < 4; i++){
                nx = dx[i] + u.first;
                ny = dy[i] + u.second;
                
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && image[nx][ny] == cl){
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                    image[nx][ny] = color;
                }
            }
            
            q.pop();
        }
        return image;
    }
};