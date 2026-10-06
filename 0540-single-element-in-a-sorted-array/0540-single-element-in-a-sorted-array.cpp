class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int l = 0;
        int r = nums.size() - 1;

        while (l < r) {

            int mid = l + (r - l) / 2;

            // Make mid even
            if (mid % 2 == 1)
                mid--;

            // Pair is correct → single is on right
            if (nums[mid] == nums[mid + 1]) {
                l = mid + 2;
            }
            // Pair is broken → single is on left or mid
            else {
                r = mid;
            }
        }

        return nums[l];
    }
};