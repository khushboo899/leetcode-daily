class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Start from second last row and move upwards
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                int best = matrix[i+1][j]; // down
                if (j > 0) best = min(best, matrix[i+1][j-1]); // down-left
                if (j < n-1) best = min(best, matrix[i+1][j+1]); // down-right
                matrix[i][j] += best;
            }
        }
        
        return *min_element(matrix[0].begin(), matrix[0].end());
    }
};
