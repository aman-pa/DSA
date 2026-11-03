class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int m=INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]>m)m=nums[i];
        }
        int c=0;
        for(int i=0;i<n;i++){
            while(nums[i]<m){
                c+=1;
                nums[i]++;
            }
        }
        return c;
    }
};