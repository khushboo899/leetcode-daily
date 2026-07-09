class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();
        if(m>n) return false;
        vector<int>freq(26,0);
        vector<int>window(26,0);
        for(char c:s1){
            freq[c-'a']++;
        }
        for(int i=0;i<m;i++){
            window[s2[i]-'a']++;
        }
        if(window==freq) return true;
        for(int i=m;i<n;i++){
            window[s2[i]-'a']++;
            window[s2[i-m]-'a']--;
            if(window==freq) return true;
        }
        return false;
    }
};