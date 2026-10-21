class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();

        vector<vector<int>> ans = mat;
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(r, vector<int>(c, 0));

        int ndr[] = {-1, 1, 0, 0};
        int ndc[] = {0, 0, -1, 1};
         for (int i = 0; i < r; i++) {
         for (int j = 0; j < c; j++) {
            if (mat[i][j] == 0) {
            q.push({{i, j}, 0});
            vis[i][j] = 1;
                }
             }
        }

        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dis = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr=row+ndr[i];
                int nc=col+ndc[i];
                if(nr>=0&&nr<r&&nc>=0&&nc<c&&!vis[nr][nc]){
                    q.push({{nr,nc},dis+1});
                    if(!vis[nr][nc]){vis[nr][nc]=1;
                    ans[nr][nc]=dis+1;
                    }

                }
            }
        }

        return ans;
    }
};