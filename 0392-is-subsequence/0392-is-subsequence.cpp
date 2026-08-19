class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size(),k=t.size();
        if(n==0&&k==0)return true;
        if(n>k)return false;
        int i=0,j=0;
        while(j<k){
            if(s[i]==t[j]){
                i++;
              
            }
            if(i==n)return true;
           
            else j++;
        }
      
  return false;
      
      
        
    }
};