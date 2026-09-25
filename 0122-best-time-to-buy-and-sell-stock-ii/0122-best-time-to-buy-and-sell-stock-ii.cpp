class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int bb=prices[0];
        int p=0;
        for(int i=1;i<n;i++){
            int bs=prices[i];
            if(bs>bb){
                p+=(bs-bb);
            }
            bb=prices[i];
        }
        return p;
    }
};