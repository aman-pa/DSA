class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        if(grid[0][0] == 1 || grid[r-1][c-1] == 1) return -1;
        queue<pair<pair<int,int>,int>>q;
       vector<vector<int>> vis(r, vector<int>(c, 1e9));
       int dr[] = {0, -1, -1, -1, 0, 1, 1, 1};
        int dc[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        vis[0][0]=1;
        q.push({{0,0},1});
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int dis=q.front().second;
            q.pop();
            if(row==r-1&&col==c-1)return dis;
            for(int i=0;i<8;i++){
                int nr=row+dr[i];
                int nc=col+dc[i];
                if(nr>=0&&nr<r&&nc>=0&&nc<c&&grid[nr][nc]==0&&dis + 1 < vis[nr][nc]){
                    vis[nr][nc]=dis+1;
                    q.push({{nr,nc},dis+1});
                }
            }
        }
        return -1;
    }
};