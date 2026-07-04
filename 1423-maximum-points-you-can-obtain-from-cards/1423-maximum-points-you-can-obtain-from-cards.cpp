class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n=card.size()-1;
        int ls=0,rs=0,ans=0;
       for(int i=0;i<k;i++){
        ls+=card[i];
       }
       ans=ls;

       for(int i=k-1;i>=0;i--){
            ls=ls-card[i];
            rs+=card[n];
            ans=max(ans,rs+ls);
            n--;
       }
       return ans;





    }
};