class Solution {
public:
     vector<string>ans;
    struct Comparator{
        bool operator()(pair<int,string>&a,pair<int,string>&b){
           if(a.first==b.first){
            return a.second>b.second;
           }
           else{
            return a.first<b.first;
           }
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int,string>,vector<pair<int,string>>,Comparator>pq;
        map<string,int>mpp;
        for(string x:words)mpp[x]++;
        for(auto it:mpp)pq.push({it.second,it.first});
        while(ans.size()!=k){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;




    }
};