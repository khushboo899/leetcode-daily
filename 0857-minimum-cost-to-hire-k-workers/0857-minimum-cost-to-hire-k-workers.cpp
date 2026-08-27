class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double,int>> workers;
        
        // Store ratio and quality
        for (int i = 0; i < n; i++) {
            workers.push_back({(double)wage[i] / quality[i], quality[i]});
        }
        
        // Sort by ratio ascending
        sort(workers.begin(), workers.end());
        
        priority_queue<int> pq; // max-heap for qualities
        int sum = 0;
        double ans = 1e18;
        
        for (auto &w : workers) {
            sum += w.second;
            pq.push(w.second);
            
            if ((int)pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }
            
            if ((int)pq.size() == k) {
                ans = min(ans, sum * w.first);
            }
        }
        
        return ans;
    }
};
