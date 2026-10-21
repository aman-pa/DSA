class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int r=board.size();
        int c=board[0].size();
        vector<vector<int>>vis(r,vector<int>(c,0));
        queue<pair<int,int>>q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if((board[i][j]=='O')&&(i==0||i==r-1||j==0||j==c-1)){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        int ndr[]={0,0,-1,1};
        int ndc[]={-1,1,0,0};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=row+ndr[i];
                int nc=col+ndc[i];
                if(nr>=0&&nr<r&&nc>=0&&nc<c&&board[nr][nc]=='O'){
                    if(!vis[nr][nc]){
                        q.push({nr,nc});
                        vis[nr][nc]=1;}
                }
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(!vis[i][j]&&board[i][j]=='O'){
                   board[i][j]='X';
                }
            }
        }
    }
};