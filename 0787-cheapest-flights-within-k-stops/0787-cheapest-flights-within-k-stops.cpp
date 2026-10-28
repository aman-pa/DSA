class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<flights.size();i++){
            int f=flights[i][0];
            int t=flights[i][1];
            int p=flights[i][2];
            adj[f].push_back({t,p});
        }
        queue<pair<int,pair<int,int>>>pq;
        vector<int>dis(n,INT_MAX);
        dis[src]=0;
        pq.push({0,{src,0}});
        while(!pq.empty()){
            auto it=pq.front();
            int stops=it.first;
            int city=it.second.first;
            int cost=it.second.second;
            pq.pop();
            if(stops>k)continue;
            for(auto iit:adj[city]){
                int nc=iit.first;
                int costnew=iit.second+cost;
                if(costnew<dis[nc]&&stops<=k){
                    dis[nc]=costnew;
                    pq.push({stops+1,{nc,costnew}});
                }
                
            }

        }
        if(dis[dst]!=INT_MAX)return dis[dst];
        return -1;
    }
};