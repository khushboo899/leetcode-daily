class Solution {
    bool isvalid(char ch){
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')){
            return true;
        }else return false;
    }
    char convertToLower(char ch){
        if((ch>='a' && ch<='z') || (ch>='0' && ch<='9')){
            return ch;
        }else{
            char temp=ch-'A'+'a';
            return temp;
        }
    }
    bool checkPalindrome(string s){
        int l=0;
        int r=s.length()-1;
        while(l<=r){
            if(s[l]!=s[r]){
                return false;
            }else{
                l++;
                r--;
            }
        }
         return true;
    }    
public:
   bool isPalindrome(string s) {
        string temp = "";
        for (int i = 0; i < s.length(); i++) {
            if (isvalid(s[i])) {
                temp.push_back(convertToLower(s[i]));
            }
        }
        return checkPalindrome(temp);
    }
};