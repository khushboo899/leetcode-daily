class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        unordered_map<string,int> freq;
        vector<string> ans;

        for (int i = 0; i <= n - 10; i++) {
            string sub = s.substr(i, 10);
            freq[sub]++;
        }

        for (auto &p : freq) {
            if (p.second > 1) {
                ans.push_back(p.first);
            }
        }
        return ans;
    }
};
