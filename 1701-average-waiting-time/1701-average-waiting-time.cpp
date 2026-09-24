class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n=customers.size();
        int s=0,f=0;
       long long  ans=0;
        for(int i=0;i<n;i++){
            int currarr=customers[i][0];
            if(currarr<f){
                s=f;
            }
            else {
             s = currarr;
}
             f=s+customers[i][1];
             ans+=f-currarr;

        }
        return (double)ans/n;
    }
};