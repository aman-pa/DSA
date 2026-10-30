
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        
        vector<vector<pair<int,int>>> adj(n);

        for(auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        vector<vector<long long>> dist(n, vector<long long>(k + 1, LLONG_MAX));

        priority_queue<
            tuple<long long,int,int>,
            vector<tuple<long long,int,int>>,
            greater<tuple<long long,int,int>>
        > pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while(!pq.empty()) {

            auto [d, node, cnt] = pq.top();
            pq.pop();

            if(d != dist[node][cnt]) continue;

            if(node == n - 1) return d;

            for(auto &it : adj[node]) {

                int next = it.first;
                int wt = it.second;

                int newCnt = (labels[node] == labels[next]) ? cnt + 1 : 1;

                if(newCnt > k) continue;

                long long newDist = d + wt;

                if(newDist < dist[next][newCnt]) {
                    dist[next][newCnt] = newDist;
                    pq.push({newDist, next, newCnt});
                }
            }
        }

        return -1;
    }
};
