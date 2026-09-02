class Solution {
public:
    bool search(vector<int>&nums,int n,int  &original,long long int &k){
         for(int i=0;i<n;i++){
            if(nums[i]==original){k*=2;
            original=k;
            return true;}
        }
        return false;
    }
    int findFinalValue(vector<int>& nums, int original) {
        int n=nums.size();
        long long int k=original;
        while(true){
            bool res=search(nums,n,original,k);
            if(res==true)continue;
            else return k;
        }
        return k;
       
    }
};