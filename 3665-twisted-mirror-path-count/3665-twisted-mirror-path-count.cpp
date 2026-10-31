class Solution {
public:
    const int MOD = 1e9 + 7;
    int m, n;
    vector<vector<vector<pair<int,int>>>> dp;
    vector<vector<vector<bool>>> vis;

    pair<int,int> solve(vector<vector<int>>& grid, int i, int j, int dir) {
        if (i >= m || j >= n)
            return {-1, -1};

        if (grid[i][j] == 0)
            return {i, j};

        if (vis[i][j][dir])
            return dp[i][j][dir];

        vis[i][j][dir] = true;

        pair<int,int> ans;

        if (dir == 0)
            ans = solve(grid, i + 1, j, 1);
        else
            ans = solve(grid, i, j + 1, 0);

        return dp[i][j][dir] = ans;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        dp.assign(m, vector<vector<pair<int,int>>>(n, vector<pair<int,int>>(2)));
        vis.assign(m, vector<vector<bool>>(n, vector<bool>(2, false)));

        vector<vector<int>> ways(m, vector<int>(n, 0));

        ways[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (ways[i][j] == 0)
                    continue;

                if (i == m - 1 && j == n - 1)
                    continue;

                if (j + 1 < n) {
                    auto p = solve(grid, i, j + 1, 0);

                    if (p.first != -1) {
                        ways[p.first][p.second] =
                            (ways[p.first][p.second] + ways[i][j]) % MOD;
                    }
                }

                if (i + 1 < m) {
                    auto p = solve(grid, i + 1, j, 1);

                    if (p.first != -1) {
                        ways[p.first][p.second] =
                            (ways[p.first][p.second] + ways[i][j]) % MOD;
                    }
                }
            }
        }

        return ways[m - 1][n - 1];
    }
};