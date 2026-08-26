class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        map<char,int>mpp;
        int i=0,j=0;
        vector<string>v;
        while(j<n){
            char c=s[j];
            mpp[c]++;
            if(mpp['1']>k){
                while(mpp['1']>k){
                    mpp[s[i]]--;
                    i++;
                }
            }
             if(mpp['1']==k){
                while(mpp['1']==k){
                     v.push_back(s.substr(i,j-i+1));
                     if(s[i]=='0')
                     i++;
                     else break;
                }
            }
            j++;
        }
        vector<int>sizes;
        for(int i=0;i<v.size();i++){
            sizes.push_back(v[i].size());
        }
        int m = INT_MAX;
        int index = -1;

        for(int i = 0; i < sizes.size(); i++) {

            if(sizes[i] < m) {
                m = sizes[i];
                index = i;
            }
            else if(sizes[i] == m && v[i] < v[index]) {
                index = i;
            }
        }
        
        if(index!=-1)
        return v[index];
        return"";

    }
};