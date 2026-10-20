class Solution {
public:
    void bfs(int i, int j, vector<vector<char>>& grid, vector<vector<char>>& vis) {
        int r = grid.size();
        int c = grid[0].size();

        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = '1';

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = row + dr[k];
                int nc = col + dc[k];

                if (nr >= 0 && nr < r && nc >= 0 && nc < c &&
                    grid[nr][nc] == '1' && vis[nr][nc] == '0') {
                    vis[nr][nc] = '1';
                    q.push({nr, nc});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int ct = 0;

        vector<vector<char>> vis(r, vector<char>(c, '0'));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (vis[i][j] == '0' && grid[i][j] == '1') {
                    ct++;
                    bfs(i, j, grid, vis);
                }
            }
        }

        return ct;
    }
};