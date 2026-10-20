class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<int>& vis, int node) {
        vis[node] = 1;

        for (int j = 0; j < isConnected.size(); j++) {
            if (isConnected[node][j] == 1 && vis[j] == 0) {
                dfs(isConnected, vis, j);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int ct = 0;
        vector<int> vis(n, 0);

        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                ct++;
                dfs(isConnected, vis, i);
            }
        }

        return ct;
    }
};