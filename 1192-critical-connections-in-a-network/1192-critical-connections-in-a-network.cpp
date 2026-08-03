class Solution {
public:
    int time;
    vector<int> dt, low;

    void dfs(int u, int parU, vector<vector<int>>& adj, vector<vector<int>>& cc) {
        dt[u] = low[u] = ++time;

        for (int v : adj[u]) {
            if (dt[v] == -1) {
                dfs(v, u, adj, cc);
                low[u] = min(low[u], low[v]);

                if (low[v] > dt[u]) {
                    cc.push_back({u, v});
                }
            } else if (v != parU) {
                low[u] = min(low[u], dt[v]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);  // ✅ Resize adjacency list
        for (auto &edge : connections) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        time = 0;
        dt.assign(n, -1);  // ✅ Proper initialization
        low.assign(n, 0);

        vector<vector<int>> bridges;
        for (int i = 0; i < n; i++) {
            if (dt[i] == -1) {
                dfs(i, -1, adj, bridges);
            }
        }

        return bridges;
    }
};
