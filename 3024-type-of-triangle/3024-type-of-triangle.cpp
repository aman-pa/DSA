class Solution {
public:
    string triangleType(vector<int>& nums) {
        int c=0;
        sort(nums.begin(), nums.end());

        if(nums[0] + nums[1] <= nums[2])
        return "none";
       map<int,int>mpp;
       for(int x:nums)mpp[x]++;
       if(mpp.size()==1)return "equilateral";
       if(mpp.size()==2)return "isosceles";
      else return "scalene";
    }
};