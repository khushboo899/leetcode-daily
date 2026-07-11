class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];

        int prev2=nums[0];
        int prev=max(nums[0],nums[1]);

        for(int i=2;i<n;i++){
            int taken=prev2+nums[i];
            int not_taken=prev;
            int curr=max(taken,not_taken);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};