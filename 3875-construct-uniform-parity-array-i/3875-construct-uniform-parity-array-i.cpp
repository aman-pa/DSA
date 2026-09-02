class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        vector<int>ans(n);
       int e=0;
       for(int i=0;i<n;i++){
        if(nums1[i]%2==0)e++;
       }
       int o=n-e;
       if(e==n)return true;
       if(e==0)return true;
       if(o-e==1)return true;
       return true ;
     

    }
};