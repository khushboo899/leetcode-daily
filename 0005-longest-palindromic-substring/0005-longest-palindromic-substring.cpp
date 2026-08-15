class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        int start=0,maxlen=1;
        int n=s.size();

        auto expand=[&](int left,int right){
            while(left>=0 && right<n && s[left]==s[right]){
                if(right-left+1>maxlen){
                    start=left;
                    maxlen=right-left+1;
                }
                left--;
                right++;
            }
        };

        for(int i=0;i<n;i++){
            expand(i,i);
            expand(i,i+1);
        }
        return s.substr(start,maxlen);
    }
};