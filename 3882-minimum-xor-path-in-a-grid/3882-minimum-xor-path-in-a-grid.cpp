class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int limit = 1;
        for (auto& row : grid) {
            for (int val : row) {
                limit = max(limit, val + 1);
            }
        }

        int bits = 1;
        while (bits < limit) {
            bits *= 2;
        }

        vector<vector<bool>> dp(n, vector<bool>(bits, false));
        dp[0][0] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    for (int x = bits - 1; x >= 0; x--) {
                        dp[j][x] = (x == grid[0][0]);
                    }
                    continue;
                }

                vector<bool> curr(bits, false);

                for (int x = 0; x < bits; x++) {
                    if (dp[j][x]) {
                        curr[x ^ grid[i][j]] = true;
                    }

                    if (j > 0 && dp[j - 1][x]) {
                        curr[x ^ grid[i][j]] = true;
                    }
                }

                dp[j] = curr;
            }
        }

        for (int x = 0; x < bits; x++) {
            if (dp[n - 1][x]) {
                return x;
            }
        }

        return 0;
    }
};