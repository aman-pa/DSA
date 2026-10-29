
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int mod = 1e9 + 7;

        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>> pq;

        vector<pair<int, int>> adj[n];
        vector<int> ways(n, 0);
        vector<long long> st(n, LLONG_MAX);

        for (int i = 0; i < roads.size(); i++) {
            int f = roads[i][0];
            int t = roads[i][1];
            int time = roads[i][2];

            adj[f].push_back({t, time});
            adj[t].push_back({f, time});
        }

        ways[0] = 1;
        st[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            long long tm = pq.top().first;
            int ct = pq.top().second;
            pq.pop();

            if (tm > st[ct]) continue;

            for (auto it : adj[ct]) {
                int nc = it.first;
                int nt = it.second;
                long long newtime = tm + nt;

                if (newtime < st[nc]) {
                    st[nc] = newtime;
                    ways[nc] = ways[ct];
                    pq.push({newtime, nc});
                }
                else if (newtime == st[nc]) {
                    ways[nc] = (ways[nc] + (long long)ways[ct]) % mod;
                }
            }
        }

        return ways[n - 1];
    }
};
