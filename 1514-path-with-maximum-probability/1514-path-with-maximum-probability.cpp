class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
       priority_queue<pair<double,int>> pq;
       pq.push({1.0,start});
       vector<double>dij(n,0);
       dij[start]=1.0;
       vector<pair<double,int>>adj[n];
       for(int i=0;i<edges.size();i++){
        int a=edges[i][0];
        int b=edges[i][1];
        double c=succProb[i];
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
       }
       while(!pq.empty()){
        int node=pq.top().second;
    double pro=pq.top().first;
        pq.pop();
        for(auto it:adj[node]){
            int no=it.second;
            double pb=it.first;
            if(pb*pro>dij[no]){
                dij[no]=pb*pro;
                pq.push({pb*pro,no});
            }
        }
       }
      return dij[end];

    }
};