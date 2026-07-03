class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        int l=0,r=0,c=0;
        while(r<n){
            if(nums[r]==0){
                c++;
                
            }
            while(c>k){
                if(nums[l]==0)c--;
                l++;
            }
            ans=max(r-l+1,ans);
           r++;
        }
        return ans;

        
    }
};