class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size(),k=n-1;
        for(int i=0;i<n;i++){
            if(i-1>=0){
            if(nums[i]!=nums[i-1]+1){k=i-1;break;}}
        }
        int s=0;
        for(int i=0;i<=k;i++)s+=nums[i];
        while(true){
            bool found=false;
            for(int i=0;i<n;i++){
                if(nums[i]==s){
                    found=true;
                    break;
                }
            }
                if(found)
                s++;
                else break;
        }
        return s;
    }
};