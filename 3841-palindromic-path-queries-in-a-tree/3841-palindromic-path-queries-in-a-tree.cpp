class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> up(LOG, vector<int>(n));
        vector<int> tin(n), tout(n), depth(n), mask(n);
        vector<int> parent(n, -1);
        int timer = 0;

        vector<int> st;
        st.push_back(0);
        parent[0] = 0;

        while (!st.empty()) {
            int u = st.back();
            st.pop_back();

            if (tin[u] == -1) continue;
        }

        fill(tin.begin(), tin.end(), -1);

        vector<pair<int, int>> dfs;
        dfs.push_back({0, 0});

        while (!dfs.empty()) {
            auto [u, state] = dfs.back();
            dfs.pop_back();

            if (state == 0) {
                tin[u] = timer++;
                mask[u] = 1 << (s[u] - 'a');

                dfs.push_back({u, 1});

                for (int i = (int)adj[u].size() - 1; i >= 0; i--) {
                    int v = adj[u][i];
                    if (v == parent[u]) continue;

                    parent[v] = u;
                    depth[v] = depth[u] + 1;
                    dfs.push_back({v, 0});
                }
            } else {
                tout[u] = timer;
            }
        }

        for (int i = 0; i < n; i++)
            up[0][i] = parent[i];

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++)
                up[j][i] = up[j - 1][up[j - 1][i]];
        }

        vector<int> rootMask(n);
        vector<int> order(n);
        for (int i = 0; i < n; i++) order[tin[i]] = i;

        for (int i = 0; i < n; i++) {
            int u = order[i];
            rootMask[u] = mask[u] ^ (u == 0 ? 0 : rootMask[parent[u]]);
        }

        vector<int> fenwick(n + 2, 0);

        auto add = [&](int idx, int val) {
            for (int i = idx + 1; i <= n + 1; i += i & -i)
                fenwick[i] ^= val;
        };

        auto rangeXor = [&](int l, int r, int val) {
            add(l, val);
            if (r < n) add(r, val);
        };

        auto pointQuery = [&](int idx) {
            int res = 0;
            for (int i = idx + 1; i > 0; i -= i & -i)
                res ^= fenwick[i];
            return res;
        };

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);

            int diff = depth[u] - depth[v];

            for (int j = 0; j < LOG; j++)
                if (diff & (1 << j))
                    u = up[j][u];

            if (u == v) return u;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[j][u] != up[j][v]) {
                    u = up[j][u];
                    v = up[j][v];
                }
            }

            return parent[u];
        };

        vector<bool> ans;

        for (string& q : queries) {
            string type;
            int u, v;
            stringstream ss(q);
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                int newMask = 1 << (c - 'a');
                int delta = mask[u] ^ newMask;

                rangeXor(tin[u], tout[u], delta);
                mask[u] = newMask;
            } else {
                ss >> v;

                int w = lca(u, v);
                int a = rootMask[u] ^ pointQuery(tin[u]);
                int b = rootMask[v] ^ pointQuery(tin[v]);

                int pathMask = a ^ b ^ mask[w];
                ans.push_back((pathMask & (pathMask - 1)) == 0);
            }
        }

        return ans;
    }
};