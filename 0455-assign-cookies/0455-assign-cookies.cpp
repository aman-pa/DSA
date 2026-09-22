class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m=g.size(),n=s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0,j=0,c=0;
        while(i<m&&j<n){
            if(g[i]<=s[j]){
                c+=1;
                i++;j++;
            }
            else j++;
        }
        return c;
    }
};