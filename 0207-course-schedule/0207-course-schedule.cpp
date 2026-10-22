class Solution {
public:
    bool dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& pathvis) {
        vis[node] = 1;
        pathvis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, adj, vis, pathvis))
                    return true;
            }
            else if (pathvis[it]) {
                return true;
            }
        }

        pathvis[node] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses, 0);
        vector<int> pathvis(numCourses, 0);
        vector<int> adj[numCourses];

        for (int i = 0; i < prerequisites.size(); i++) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];
            adj[b].push_back(a);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, pathvis))
                    return false;
            }
        }

        return true;
    }
};