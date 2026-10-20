class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>&ans,vector<vector<int>>&image,int color,int dr[],int dc[],int ic){
        ans[r][c]=color;
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0&&nr<n&&nc>=0&&nc<m&&image[nr][nc]==ic&&ans[nr][nc]!=color){
                dfs(nr,nc,ans,image,color,dr,dc,ic);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ic=image[sr][sc];
        vector<vector<int>>ans=image;
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};
        dfs(sr,sc,ans,image,color,dr,dc,ic);
        return ans;
    }
};