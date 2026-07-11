class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1);
        long long prev = 1;

        for (int j = 1; j < rowIndex; j++) {
            long long curr = prev * (rowIndex - j + 1) / j;
            row[j] = (int)curr;
            prev = curr;
        }
        return row;
    }
};
