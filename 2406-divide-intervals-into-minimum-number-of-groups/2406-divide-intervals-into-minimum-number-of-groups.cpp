class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<int>arr,dep;
        for(int i=0;i<n;i++){
            int a=intervals[i][0];
            int d=intervals[i][1];
            arr.push_back(a);
            dep.push_back(d);
        }
        int c=0,maxc=0;
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int i=0,j=0;
        while(i<n){
            if(arr[i]<=dep[j]){
                c++;
                i++;
            }
            else{
                c--;
                j++;
            }
            maxc=max(c,maxc);
        }
        return maxc;
    }
};