class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            // Push opening brackets
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                // If closing bracket, stack must not be empty and top must match
                if (st.empty()) return false;
                char top = st.top();
                st.pop();
                if ((c == ')' && top != '(') ||
                    (c == ']' && top != '[') ||
                    (c == '}' && top != '{'))
                    return false;
            }
        }
        // Valid if no unmatched opening brackets remain
        return st.empty();
    }
};
