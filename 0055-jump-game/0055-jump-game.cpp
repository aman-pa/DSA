class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int m=0;
        for(int i=0;i<n;i++){
            if(i>m)return false;
            m=max(m,i+nums[i]);
        }
        return true;
    }
};