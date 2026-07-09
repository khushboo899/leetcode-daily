class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        int m=s.size();
        int n=p.size();
        if(n>m) return ans;
        vector<int>freq(26,0);
        vector<int>window(26,0);
        for(char c:p){
            freq[c-'a']++;
        }
        for(int i=0;i<n;i++){
            window[s[i]-'a']++;
        }
        if(window==freq){
            ans.push_back(0);
        }
        for(int i=n;i<m;i++){
            window[s[i]-'a']++;
            window[s[i-n]-'a']--;
            if(window==freq){
                ans.push_back(i-n+1); 
            }    
        }
        return ans;
    }
};