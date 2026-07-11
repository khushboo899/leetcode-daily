class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        
        int prev2 = 1, prev = 2; // f(1), f(2)
        for (int i = 3; i <= n; i++) {
            int c = prev2 + prev;
            prev2 = prev;
            prev = c;
        }
        return prev;
    }
};
