class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dij(n+1,INT_MAX);
        pq.push({0,k});
        dij[k]=0;
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<times.size();i++){
            int a=times[i][0];
            int b=times[i][1];
            int c=times[i][2];
            adj[a].push_back({b,c});
        }
        while(!pq.empty()){
            int node=pq.top().second;
            int dis=pq.top().first;
            pq.pop();
            for(auto it:adj[node]){
                int d=it.second;
                int e=it.first;
                if(d+dis<dij[e]){
                    dij[e]=d+dis;
                    pq.push({d+dis,e});
                }
            }
        }
        for(int i=1;i<dij.size();i++){
            if(dij[i]==INT_MAX)return -1;
        }
        int ans=*max_element(dij.begin()+1,dij.end());
        return ans;
       

    }
};