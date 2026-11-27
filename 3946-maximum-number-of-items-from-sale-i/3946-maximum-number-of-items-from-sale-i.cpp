class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int mn = INT_MAX;

        vector<int> val(n, 1);

        for (auto &x : items)
            mn = min(mn, x[1]);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0)
                    val[i]++;
            }
        }

        vector<int> dp(budget + 1, -1);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            int cost = items[i][1];

            for (int b = budget; b >= cost; b--) {
                if (dp[b - cost] != -1)
                    dp[b] = max(dp[b], dp[b - cost] + val[i]);
            }
        }

        int ans = 0;

        for (int b = 0; b <= budget; b++) {
            if (dp[b] != -1)
                ans = max(ans, dp[b] + (budget - b) / mn);
        }

        return ans;
    }
};