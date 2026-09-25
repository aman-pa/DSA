class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int n=position.size();
        int m=INT_MAX;
        for(int i=0;i<n;i++){
            int c=0;
            int k=position[i];
           for(int j=0;j<n;j++){
                int l=position[j];
                if((abs(l-k))%2==0){
                   continue;
                }
                if((abs(l-k))%2!=0){
                    c+=1;
                }
                
        }
                        m=min(m,c);
        }
        return m;
    }
};