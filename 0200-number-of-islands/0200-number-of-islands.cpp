class Solution {
public:
    void bfs(vector<vector<char>>& grid,int i,int j){
        int m=grid.size();
        int n=grid[0].size(); 
        queue<pair<int,int>>q;
        q.push({i,j});
        grid[i][j]='0';

        while(!q.empty()){
            auto [x,y] = q.front(); q.pop();
            vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
            for (auto [dx,dy] : dirs) {
                int nx = x+dx, ny = y+dy;
                if (nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]=='1') {
                    grid[nx][ny] = '0';
                    q.push({nx,ny});
                }
            }    
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int land=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    land++;
                    bfs(grid,i,j);
                }
            }
        }
        return land;
    }
};