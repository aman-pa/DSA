class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
         int n=intervals.size();
        int e=intervals[0][1];
        int s=intervals[0][0];
        vector<vector<int>>ans;
        ans.push_back({intervals[0][0],intervals[0][1]});
        for(int i=1;i<n;i++){
            int ns=intervals[i][0];
            int ne=intervals[i][1];
            if(ns<=e){
                ans.pop_back();
                ans.push_back({min(s,ns),max(e,ne)});
                s=min(s,ns);
                e=max(e,ne);
            }
            else {ans.push_back({ns,ne});
            s=ns;
            e=ne;
            }
        }
        return ans;
    }
};