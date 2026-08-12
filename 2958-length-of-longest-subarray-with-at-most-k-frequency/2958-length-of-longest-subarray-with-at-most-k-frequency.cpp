class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=-1;
        unordered_map<int,int>mpp;
        int i=0,j=0;
        int s=0;
        while(j<=n-1){
            mpp[nums[j]]++;
           
                while(mpp[nums[j]]>k){
                mpp[nums[i]]--;
                i++;
                }
                
            
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;

    }
};