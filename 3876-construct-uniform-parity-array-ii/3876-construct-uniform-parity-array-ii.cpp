class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        int ev=0;
        for(int x:nums1){
            if(x%2==0)ev++;
        }
        int odd=n-ev;
        int smallest=INT_MAX;
        int smalleven=INT_MAX,smallodd=INT_MAX;
        for(int x:nums1){
            if(x<smalleven&&x%2==0)smalleven=x;
            if(x<smallodd&&x%2!=0)smallodd=x;
            if(x<smallest)smallest=x;
        }

        sort(nums1.begin(),nums1.end());
        int k=-1;
        if(nums1[0]%2==0)k=1;
        for(int i=1;i<n;i++){
            if(nums1[i]%2==0&&k==-1){
                if(smallodd>nums1[i])return false;

                else continue;
            }
            if(nums1[i]%2!=0&&k==1){
                if(smalleven<nums1[i])return false;
                else continue;
            }
            
        }

            return true;

    }
};