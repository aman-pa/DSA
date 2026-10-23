class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& WordList) {
        queue<pair<string,int>>q;
        unordered_set<string>st(WordList.begin(),WordList.end());
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty()){
            string s=q.front().first;
            int k=q.front().second;
            q.pop();
            if(s==endWord)return k;
            for(int i=0;i<s.size();i++){
                char ori=s[i];
                for(char j='a';j<='z';j++){
                    s[i]=j;
                    if(st.find(s)!=st.end()){
                        st.erase(s);
                        q.push({s,k+1});
                    }
                }
                s[i]=ori;
                
            }
        }
        return 0;

    }
};