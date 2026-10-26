class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0 && !vis[i][j]) {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vis[i][j] = true;
                    long long sum = 0;

                    while (!q.empty()) {
                        auto p = q.front();
                        q.pop();

                        int x = p.first;
                        int y = p.second;
                        sum += grid[x][y];

                        for (int d = 0; d < 4; d++) {
                            int nx = x + dx[d];
                            int ny = y + dy[d];

                            if (nx >= 0 && nx < m &&
                                ny >= 0 && ny < n &&
                                grid[nx][ny] > 0 &&
                                !vis[nx][ny]) {
                                vis[nx][ny] = true;
                                q.push({nx, ny});
                            }
                        }
                    }

                    if (sum % k == 0) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};