class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;

        // Step 1: Push all boundary land cells into queue
        for (int i = 0; i < m; i++) {
            for (int j : {0, n-1}) {
                if (grid[i][j] == 1) {
                    q.push({i,j});
                    grid[i][j] = 0;
                }
            }
        }
        for (int j = 0; j < n; j++) {
            for (int i : {0, m-1}) {
                if (grid[i][j] == 1) {
                    q.push({i,j});
                    grid[i][j] = 0;
                }
            }
        }

        // Step 2: BFS to sink boundary-connected land
        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        while (!q.empty()) {
            auto [x,y] = q.front(); q.pop();
            for (auto [dx,dy] : dirs) {
                int nx = x+dx, ny = y+dy;
                if (nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]==1) {
                    grid[nx][ny] = 0;
                    q.push({nx,ny});
                }
            }
        }

        // Step 3: Count remaining land
        int count = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 1) count++;
            }
        }
        return count;
    }
};
