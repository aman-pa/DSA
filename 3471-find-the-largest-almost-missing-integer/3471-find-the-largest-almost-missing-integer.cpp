class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>mpp;
        for(int i=0;i<=n-k;i++){
            int c=0;
            map<int,int>mp;
            for(int j=i;j<n;j++){
                mp[nums[j]]++;
                c++;
                if(c==k)break;
            }
            for(auto it:mp){
            mpp[it.first]++;
        }
        }
        int m=-1;
        
        for(auto it:mpp){
            if(it.second==1){
                if(it.first>m)m=it.first;
            }
        }
        return m;
    }
};