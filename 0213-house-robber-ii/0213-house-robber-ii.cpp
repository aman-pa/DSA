class Solution {
public:
         int helper(int s,int e,vector<int>nums,vector<int>&dp){
         dp[s] = nums[s];
        dp[s+1] = max(nums[s], nums[s+1]);
            for(int i=s+2;i<=e;i++){
                dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
            }
            return dp[e];
    }
    int rob(vector<int>& nums) {
         int n=nums.size();
        vector<int>dp(n);
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);
        int fh=helper(1,n-1,nums,dp);
        int sh=helper(0,n-2,nums,dp);
        return max(fh,sh);
    }
};