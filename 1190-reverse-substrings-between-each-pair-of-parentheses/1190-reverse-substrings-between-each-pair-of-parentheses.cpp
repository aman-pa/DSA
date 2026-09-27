class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        string res;

        for (char c : s) {
            if (c == '(') {
                st.push(res.size());
            } 
            else if (c == ')') {
                int start = st.top();
                st.pop();
                reverse(res.begin() + start, res.end());
            } 
            else {
                res += c;
            }
        }

        return res;
    }
};