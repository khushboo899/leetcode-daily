class Solution {
public:

    vector<int>par;
    vector<int>rank;

    int find(int x){
        if(par[x]==x){
            return x;
        }
        return par[x]=find(par[x]);
    }

    bool unite(int x,int y){
        int rootx=find(x);
        int rooty=find(y);

        if(rootx==rooty){
            return false;
        }
        if(rank[rootx]>rank[rooty]){
            par[rooty]=rootx;
        }else if(rank[rootx]<rank[rooty]){
            par[rootx]=rooty;
        }else{
            par[rooty]=rootx;
            rank[rootx]++;
        }
        return true;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<array<int, 3>> edges;

        // Create all possible edges
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                int cost = abs(points[i][0] - points[j][0])
                         + abs(points[i][1] - points[j][1]);

                edges.push_back({cost, i, j});
            }
        }

        // Sort by cost
        sort(edges.begin(), edges.end());

        // Initialize DSU
        par.resize(n);
        rank.assign(n, 0);

        for (int i = 0; i < n; i++)
            par[i] = i;

        int totalCost = 0;
        int count = 0;

        // Kruskal
        for (auto &[cost, u, v] : edges) {

            if (unite(u, v)) {
                totalCost += cost;
                count++;

                if (count == n - 1)
                    break;
            }
        }

        return totalCost;
    }
};