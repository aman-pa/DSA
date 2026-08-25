class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int mx=*max_element(nums.begin(),nums.end());
        set<int>s;
        int p=nums.size();
        for(int i=0;i<p;i++){
            s.insert(nums[i]);
        }
        int n=mx/k;
        for(int i=1;i<=n;i++){
            int t=k*i;
            if(s.find(t)==s.end())return t;
        }
        return k*(n+1);
    }
};