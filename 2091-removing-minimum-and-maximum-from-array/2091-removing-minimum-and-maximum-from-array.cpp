class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return 1;
        if(n==2)return 2;
        int mn=INT_MAX,mx=INT_MIN;
        int imn=-1,imx=-1;
        for(int i=0;i<n;i++){
            if(nums[i]<mn){mn=nums[i];
            imn=i;
            }
            if(nums[i]>mx){
                mx=nums[i];
                imx=i;
            }
        }
        int left=1+max(imn,imx);
        int right=n-min(imn,imx);
        int ans1=min(left,right);
        int f=1+min(imn,imx);
        int l=n-max(imn,imx);
        int ans2=f+l;
        return min(ans1,ans2);


       
        
    }
};