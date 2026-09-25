class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        int c=1;
        sort(points.begin(),points.end());
        int s=points[0][0],e=points[0][1];
        for(int i=1;i<n;i++){
            int ns=points[i][0];
            int ne=points[i][1];
            if(ns<=e){
                e=min(e,ne);
            }
            else {e=ne;c++;}
        }
        return c;
    }
};