class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int m=arr1.size(), n=arr2.size();
        int a=1,c=0;
        for(int i=0;i<m;i++){
            a=1;
            for(int j=0;j<n;j++){
                int k=abs(arr1[i]-arr2[j]);
                if(k<=d){
                    a=0;
                    break;
                }
            }
            if(a==1)c+=1;

        }
        return c;
    }
};