class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        int prev3=0 , prev2=1 , prev=1;
        for(int i=3;i<=n;i++){
            int curr = prev3 + prev2 + prev;
            prev3=prev2;
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};