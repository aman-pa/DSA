class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();

        vector<vector<bool>> palindrome(n, vector<bool>(n, false));

        // Check every substring for palindrome
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;

                if (s[i] == s[j] && (len <= 2 || palindrome[i + 1][j - 1])) {
                    palindrome[i][j] = true;
                }
            }
        }

        // dp[i] = maximum palindromes using first i characters
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];

            for (int j = 0; j < i; j++) {
                if (i - j >= k && palindrome[j][i - 1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n];
    }
};