class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;

        function<void(int, int)> solve = [&](int open, int close) {
            if (s.size() == 2 * n) {
                ans.push_back(s);
                return;
            }

            if (open < n) {
                s += '(';
                solve(open + 1, close);
                s.pop_back();
            }

            if (close < open) {
                s += ')';
                solve(open, close + 1);
                s.pop_back();
            }
        };

        solve(0, 0);
        return ans;
    }
};