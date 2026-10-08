class Solution {
public:

    bool canShip(vector<int>& weights, int days, int capacity) {

        int daysUsed = 1;
        int currentLoad = 0;

        for (int weight : weights) {

            if (currentLoad + weight <= capacity) {
                currentLoad += weight;
            }
            else {
                // Start a new day
                daysUsed++;
                currentLoad = weight;
            }
        }

        return daysUsed <= days;
    }


    int shipWithinDays(vector<int>& weights, int days) {

        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);

        int ans = r;

        while (l <= r) {

            int mid = l + (r - l) / 2;

            if (canShip(weights, days, mid)) {
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
};