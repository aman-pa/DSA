class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<score.size();i++){
            pq.push({score[i],i});
        }
        vector<string>ans(score.size());
        int c=0;
        while(pq.size()!=0){
            int i=pq.top().second;
            if(c==0)ans[i]="Gold Medal";
            else if(c==1)ans[i]="Silver Medal";
            else if(c==2)ans[i]="Bronze Medal";
            else ans[i]=to_string(c+1);
            pq.pop();
            c++;
        }
        return ans;
    }
};