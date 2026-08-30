class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int xorr = 0;
        for(int x:nums)xorr^=x;
        int g1=0,g2=0;
        int mask=xorr&(-xorr);
        for(int x:nums){
            if(x&mask)g1^=x;
            else g2^=x;
        }
        return {g1,g2};

    }
};