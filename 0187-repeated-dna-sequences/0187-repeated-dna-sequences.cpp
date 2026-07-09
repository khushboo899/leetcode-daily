class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.size();
        unordered_set<string>seen;
        unordered_set<string>repeat;
        for(int i=0;i<=n-10;i++){
            string sub=s.substr(i,10);
            if(seen.count(sub)){
                repeat.insert(sub);
            }else{
                seen.insert(sub);
            }
        }
        vector<string>ans(repeat.begin(),repeat.end());
        return ans;    
    }
};