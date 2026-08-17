class Solution {
public:
    bool dfs(int node, int currColor,
             vector<vector<int>>& adj,
             vector<int>& color) {

        color[node] = currColor;

        for (int neighbor : adj[node]) {

            // If neighbor is not colored
            if (color[neighbor] == -1) {

                if (!dfs(neighbor, 1 - currColor, adj, color))
                    return false;
            }

            // Neighbor already has same color
            else if (color[neighbor] == currColor) {
                return false;
            }
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        vector<vector<int>> adj(n + 1);

        // Build graph
        for (auto &edge : dislikes) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> color(n + 1, -1);

        // Handle disconnected components
        for (int i = 1; i <= n; i++) {

            if (color[i] == -1) {

                if (!dfs(i, 0, adj, color))
                    return false;
            }
        }

        return true;
    }
};