class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
  priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
  int r=heights.size();
  int c=heights[0].size();
  vector<vector<int>>eff(r,vector<int>(c,INT_MAX));
  eff[0][0]=0;
  pq.push({0,{0,0}});
  int ndr[]={0,-1,0,1};
  int ndc[]={-1,0,1,0};
  while(!pq.empty()){
    int dis=pq.top().first;
    int row=pq.top().second.first;
    int col=pq.top().second.second;
    if(row==r-1&&col==c-1)return dis;
    pq.pop();
    if(dis > eff[row][col]) continue;
    for(int i=0;i<4;i++){
        int nr=row+ndr[i];
        int nc=col+ndc[i];
        if(nr>=0&&nr<r&&nc>=0&&nc<c){
            int h=abs(heights[nr][nc]-heights[row][col]);
            int neweff=max(dis,h);
            if(neweff<eff[nr][nc]){
                eff[nr][nc]=neweff;
                pq.push({neweff,{nr,nc}});
            }

        }
    }
  }
  return -1;
  

    }
};