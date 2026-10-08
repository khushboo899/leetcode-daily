class Solution {
public:

    bool canMake(vector<int>& bloomDay, int m, int k, int day) {

        int flowers = 0;
        int bouquets = 0;

        for (int bloom : bloomDay) {

            if (bloom <= day) {
                flowers++;

                // Enough consecutive flowers for one bouquet
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            }
            else {
                // Consecutiveness breaks
                flowers = 0;
            }
        }

        return bouquets >= m;
    }


    int minDays(vector<int>& bloomDay, int m, int k) {

        long long required = 1LL * m * k;

        if (required > bloomDay.size())
            return -1;

        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int r = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = r;

        while (l <= r) {

            int mid = l + (r - l) / 2;

            if (canMake(bloomDay, m, k, mid)) {

                // mid days are enough
                ans = mid;

                // Try fewer days
                r = mid - 1;
            }
            else {

                // mid days are not enough
                l = mid + 1;
            }
        }

        return ans;
    }
};