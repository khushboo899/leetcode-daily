class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx + 1, 0);

        for (int x : nums) {
            freq[x]++;
        }

        int prev2 = 0;
        int prev1 = 0;

        for (int i = 1; i <= mx; i++) {

            int take = prev2 + i * freq[i];
            int skip = prev1;

            int curr = max(take, skip);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};