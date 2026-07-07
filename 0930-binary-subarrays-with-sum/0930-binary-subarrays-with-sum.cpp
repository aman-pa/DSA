class Solution {
public:
    int sumlessthanequalto(vector<int>&nums,int goal){
        int c=0;
        int l=0,r=0,s=0;
        int n=nums.size();
        while(r<n){
            if(goal<0)return 0;
            s+=nums[r];
            while(s>goal){
                s-=nums[l];
                l++;
            }
             if(s<=goal){
                c+=r-l+1;
            }
            r++;
        }
        return c;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans=sumlessthanequalto(nums,goal)-sumlessthanequalto(nums,goal-1);
        return ans;
    }
};