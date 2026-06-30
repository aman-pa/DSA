class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int k=0;
        int ans=0;
        set<char>st;
        int i=0,j=0;
        while(j<n){
            if(st.find(s[j])==st.end()){
                st.insert(s[j]);
               ans = max(ans, j - i + 1);
               j++;

               
            }
            else{
                st.erase(s[i]);
                i++;
                
            }
            
        }
        return ans;
           
    }
};