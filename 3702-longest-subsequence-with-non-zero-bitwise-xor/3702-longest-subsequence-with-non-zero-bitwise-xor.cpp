class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        // vector<int>prefix(n);
        // prefix[0]=nums[0];
        // int ans=0;
        // for(int i=1;i<n;i++){
        //     prefix[i]=prefix[i-1]^nums[i];
        // }
        // map<int,int>mpp;
        // for(int i=0;i<prefix.size();i++){
        //     mpp[prefix[i]]=i;
        // }
        bool allzero=true;
        int ans=0;
        for(int x:nums){
            ans^=x;
            if(x!=0)allzero=false;
        }
        if(allzero)return 0;
     if(ans==0)return n-1;
     else return n;

      
    }
};