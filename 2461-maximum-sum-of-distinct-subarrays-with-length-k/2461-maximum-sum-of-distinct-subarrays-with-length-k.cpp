class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        long long sum=0,ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            mp[nums[i]]++;

            if(i>=k){
                int remove=nums[i-k];
                sum-=remove;
                mp[remove]--;
                if(mp[remove]==0){
                    mp.erase(remove);
                }
            }
            if(i>=k-1){
                if(mp.size()==k){
                    ans=max(ans,sum);
                }
            }
        } 
        return ans;
    }
};