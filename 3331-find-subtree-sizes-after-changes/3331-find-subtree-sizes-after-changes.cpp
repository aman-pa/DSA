class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> newParent(n, -1);
        vector<int> last(26, -1);

        function<void(int)> dfs = [&](int node) {
            int ch = s[node] - 'a';
            int prev = last[ch];

            if (prev != -1) {
                newParent[node] = prev;
            } else {
                newParent[node] = parent[node];
            }

            last[ch] = node;

            for (int child : adj[node]) {
                dfs(child);
            }

            last[ch] = prev;
        };

        dfs(0);

        vector<vector<int>> newAdj(n);

        for (int i = 1; i < n; i++) {
            newAdj[newParent[i]].push_back(i);
        }

        vector<int> ans(n, 1);

        function<int(int)> dfs2 = [&](int node) {
            for (int child : newAdj[node]) {
                ans[node] += dfs2(child);
            }
            return ans[node];
        };

        dfs2(0);

        return ans;
    }
};