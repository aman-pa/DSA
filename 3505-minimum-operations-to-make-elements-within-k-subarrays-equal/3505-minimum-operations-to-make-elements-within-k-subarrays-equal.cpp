class Solution {
public:
    struct BIT {
        int n;
        vector<long long> bit;

        BIT(int n) {
            this->n = n;
            bit.resize(n + 1, 0);
        }

        void update(int i, long long val) {
            while (i <= n) {
                bit[i] += val;
                i += i & -i;
            }
        }

        long long query(int i) {
            long long sum = 0;

            while (i > 0) {
                sum += bit[i];
                i -= i & -i;
            }

            return sum;
        }

        int kth(int k) {
            int idx = 0;

            for (int i = 1 << 17; i > 0; i >>= 1) {
                int next = idx + i;

                if (next <= n && bit[next] < k) {
                    idx = next;
                    k -= bit[next];
                }
            }

            return idx + 1;
        }
    };

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        vector<int> vals = nums;

        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        int m = vals.size();

        BIT cnt(m), sum(m);

        auto getCost = [&]() -> long long {
            int mid = cnt.kth((x + 1) / 2);

            long long median = vals[mid - 1];

            long long leftCount = cnt.query(mid);
            long long leftSum = sum.query(mid);

            long long totalSum = sum.query(m);

            long long rightCount = x - leftCount;
            long long rightSum = totalSum - leftSum;

            return median * leftCount - leftSum
                 + rightSum - median * rightCount;
        };

        auto add = [&](int v, int sign) {
            int id = lower_bound(vals.begin(), vals.end(), v)
                     - vals.begin() + 1;

            cnt.update(id, sign);
            sum.update(id, 1LL * v * sign);
        };

        int windows = n - x + 1;

        vector<long long> cost(windows);

        for (int i = 0; i < x; i++) {
            add(nums[i], 1);
        }

        cost[0] = getCost();

        for (int i = x; i < n; i++) {
            add(nums[i - x], -1);
            add(nums[i], 1);

            cost[i - x + 1] = getCost();
        }

        const long long INF = 1e18;

        vector<vector<long long>> dp(
            k + 1, vector<long long>(n + 1, INF)
        );

        for (int i = 0; i <= n; i++) {
            dp[0][i] = 0;
        }

        for (int j = 1; j <= k; j++) {
            for (int i = 1; i <= n; i++) {

                dp[j][i] = dp[j][i - 1];

                if (i >= x && dp[j - 1][i - x] != INF) {
                    dp[j][i] = min(
                        dp[j][i],
                        dp[j - 1][i - x] + cost[i - x]
                    );
                }
            }
        }

        return dp[k][n];
    }
};