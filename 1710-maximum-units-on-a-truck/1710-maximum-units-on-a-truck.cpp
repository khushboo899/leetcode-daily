class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {

        // Sort according to units per box in descending order
        sort(boxTypes.begin(), boxTypes.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[1] > b[1];
             });

        int totalUnits = 0;

        for (auto &box : boxTypes) {

            int numberOfBoxes = box[0];
            int unitsPerBox = box[1];

            int take = min(numberOfBoxes, truckSize);

            totalUnits += take * unitsPerBox;

            truckSize -= take;

            if (truckSize == 0)
                break;
        }

        return totalUnits;
    }
};