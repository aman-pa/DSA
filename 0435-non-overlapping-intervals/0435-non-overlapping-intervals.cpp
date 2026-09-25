class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int c=0;
        sort(intervals.begin(),intervals.end());
        int l=intervals[0][1];
        for(int i=1;i<n;i++){
            int nf=intervals[i][0];
            int nl=intervals[i][1];
            if(nf<l){c+=1;
            l=min(l,nl);
            }
            else {
                l = nl;
}
        }
        return c;
    }
};