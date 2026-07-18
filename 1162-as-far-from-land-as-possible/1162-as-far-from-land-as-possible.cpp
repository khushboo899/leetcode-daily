class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {

        int n = grid.size();

        queue<pair<int,int>> q;

        vector<vector<int>> dist(n, vector<int>(n, -1));

        // Push all land cells
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        // Edge cases
        if(q.empty() || q.size() == n * n)
            return -1;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        int ans = 0;

        while(!q.empty()) {

            auto [row, col] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++) {

                int nr = row + dr[i];
                int nc = col + dc[i];

                if(nr >= 0 && nr < n &&
                   nc >= 0 && nc < n &&
                   dist[nr][nc] == -1) {

                    dist[nr][nc] = dist[row][col] + 1;
                    ans = max(ans, dist[nr][nc]);

                    q.push({nr, nc});
                }
            }
        }

        return ans;
    }
};