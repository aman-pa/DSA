class Solution {
public:
    struct Node {
        long long score;
        vector<int> indices;
        
        Node() {
            score = -1;
        }
        
        Node(long long s, vector<int> v) {
            score = s;
            indices = v;
        }
    };

    vector<vector<Node>> dp;
    vector<vector<int>> a;
    vector<int> nextIndex;
    int n;

    Node solve(int i, int k) {
        if (i == n || k == 0) {
            return Node(0, {});
        }

        if (dp[i][k].score != -1) {
            return dp[i][k];
        }

        // Don't choose current interval
        Node skip = solve(i + 1, k);

        // Choose current interval
        Node takeNext = solve(nextIndex[i], k - 1);

        Node take;
        take.score = a[i][2] + takeNext.score;
        take.indices = takeNext.indices;
        take.indices.push_back(a[i][3]);

        // Sort indices because final answer must be compared lexicographically
        sort(take.indices.begin(), take.indices.end());

        Node ans;

        if (take.score > skip.score) {
            ans = take;
        }
        else if (take.score < skip.score) {
            ans = skip;
        }
        else {
            if (take.indices < skip.indices)
                ans = take;
            else
                ans = skip;
        }

        return dp[i][k] = ans;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        n = intervals.size();

        // [left, right, weight, original_index]
        a.clear();

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by starting point
        sort(a.begin(), a.end(), [](vector<int>& x, vector<int>& y) {
            if (x[0] != y[0])
                return x[0] < y[0];

            return x[1] < y[1];
        });

        // Find next interval whose left > current right
        nextIndex.resize(n);

        vector<int> starts(n);

        for (int i = 0; i < n; i++) {
            starts[i] = a[i][0];
        }

        for (int i = 0; i < n; i++) {
            nextIndex[i] =
                upper_bound(starts.begin(), starts.end(), a[i][1])
                - starts.begin();
        }

        // At most 4 intervals
        dp.assign(n, vector<Node>(5));

        return solve(0, 4).indices;
    }
};