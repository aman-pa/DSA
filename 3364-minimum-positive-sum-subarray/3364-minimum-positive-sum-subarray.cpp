class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();

        vector<long long> pre(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + nums[i];
        }

        multiset<long long> st;
        long long ans = LLONG_MAX;

        for (int j = l; j <= n; j++) {
            st.insert(pre[j - l]);

            if (j - r - 1 >= 0) {
                auto it = st.find(pre[j - r - 1]);
                st.erase(it);
            }

            auto it = st.lower_bound(pre[j]);

            if (it != st.begin()) {
                --it;
                long long sum = pre[j] - *it;

                ans = min(ans, sum);
            }
        }

        return ans == LLONG_MAX ? -1 : (int)ans;
    }
};