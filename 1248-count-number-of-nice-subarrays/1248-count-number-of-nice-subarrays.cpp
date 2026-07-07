class Solution {
public:
    int noofsub(vector<int>&nums,int k){
        int l=0,r=0,c=0,s=0;
        while(r<nums.size()){
            if(k<0)return 0;
            if(nums[r]%2!=0)
            s+=1;
            while(s>k){
                if(nums[l]%2!=0)
             s-=1;
                l++;
            }
            c+=(r-l+1);
            r++;
        }
        return c;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans=noofsub(nums,k)-noofsub(nums,k-1);
        return ans;
    }
};