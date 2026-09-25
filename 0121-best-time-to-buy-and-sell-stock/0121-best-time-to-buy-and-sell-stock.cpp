class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int p=0;
         int bb=prices[0];
        for(int i=1;i<n;i++){
            int bs=prices[i];
            if(bs>bb){
                p=max(p,bs-bb);
            }
            if(prices[i]<bb)bb=prices[i];
        }
        return p;

    }
};