class Solution {
public:
    void bfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        int r = grid.size();
        int c = grid[0].size();

        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = 1;

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
                    grid[nr][nc] == 0 && vis[nr][nc] == 0) {
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int ct = 0;

        vector<vector<int>> vis(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            if (grid[i][0] == 0 && vis[i][0] == 0)
                bfs(i, 0, grid, vis);

            if (grid[i][c - 1] == 0 && vis[i][c - 1] == 0)
                bfs(i, c - 1, grid, vis);
        }

        for (int j = 0; j < c; j++) {
            if (grid[0][j] == 0 && vis[0][j] == 0)
                bfs(0, j, grid, vis);

            if (grid[r - 1][j] == 0 && vis[r - 1][j] == 0)
                bfs(r - 1, j, grid, vis);
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 0 && vis[i][j] == 0) {
                    ct++;
                    bfs(i, j, grid, vis);
                }
            }
        }

        return ct;
    }
};