class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dis(n, vector<int>(n, INT_MAX));

        for(int i = 0; i < n; i++) {
            dis[i][i] = 0;
        }

        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            dis[u][v] = wt;
            dis[v][u] = wt;
        }

        // Floyd-Warshall
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(dis[i][k] != INT_MAX && dis[k][j] != INT_MAX &&
                       dis[i][k] + dis[k][j] < dis[i][j]) {
                        dis[i][j] = dis[i][k] + dis[k][j];
                    }
                }
            }
        }

        int ans = -1;
        int minCount = INT_MAX;

        for(int i = 0; i < n; i++) {
            int count = 0;

            for(int j = 0; j < n; j++) {
                if(i != j && dis[i][j] <= distanceThreshold) {
                    count++;
                }
            }

            if(count <= minCount) {
                minCount = count;
                ans = i;
            }
        }

        return ans;
    }
};