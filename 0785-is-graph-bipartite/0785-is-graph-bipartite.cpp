
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            if (vis[i] == -1) {
                q.push({i, 1});
                vis[i] = 1;

                while (!q.empty()) {
                    int node = q.front().first;
                    int color = q.front().second;
                    q.pop();

                    for (auto it : graph[node]) {
                        if (vis[it] == -1) {
                            q.push({it, 1 - color});
                            vis[it] = 1 - color;
                        }
                        else if (vis[it] == color) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};
