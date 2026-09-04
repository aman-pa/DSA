class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int mx=INT_MIN;
        int mn=INT_MAX;
        int n=nums.size();
        vector<int>mx1(n);
        vector<int>mn1(n);
        for(int i=0;i<n;i++){
            if(nums[i]>mx)mx=nums[i];
            mx1[i]=mx;
        }
        for(int i=n-1;i>=0;i--){
            if(nums[i]<mn)mn=nums[i];
            mn1[i]=mn;
        }
        for(int i=0;i<n;i++){
           int p=mx1[i]-mn1[i];
           if(p<=k)return i;

        }
        return -1;
        
    }
};