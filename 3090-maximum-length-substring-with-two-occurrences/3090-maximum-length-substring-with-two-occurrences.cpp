class Solution {
public:
    int maximumLengthSubstring(string s) {
         int n=s.size();
         int ans=INT_MIN;
         map<char,int>mpp;
          int i=0,j=0;
          while(j<n){
            mpp[s[j]]++;
            if(mpp[s[j]]<=2){
                ans=max(ans,j-i+1);
            }
            else{
                while(mpp[s[j]]>2){
                    mpp[s[i]]--;
                    i++;
                }
               

            }
             j++;
          }
          return ans;
    }
};