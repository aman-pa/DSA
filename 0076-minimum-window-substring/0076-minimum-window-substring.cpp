class Solution {
public:
    string minWindow(string s, string t) {
        int l=0,r=0,c=0,si=-1,m=INT_MAX;
        string ans="";
        int hash[256]={0};
        for(int i=0;i<t.size();i++)hash[t[i]]++;
        while(r<s.size()){
            if(hash[s[r]]>0)c+=1;
            hash[s[r]]--;
            while(c==t.size()){
                if(r-l+1<m){m=r-l+1;
                si=l;}
                hash[s[l]]++;
                if(hash[s[l]]>0)c-=1;
                l++;

            }
            r++;
        }
        if(si==-1)
    return "";
        for(int i=si;i<si+m;i++)ans+=s[i];
        return ans;
    }
};