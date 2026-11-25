class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        const long long MOD1 = 1000000007LL;
        const long long MOD2 = 1000000009LL;
        const long long BASE1 = 1315423911LL % MOD1;
        const long long BASE2 = 2654435761LL % MOD2;

        vector<long long> p1(n + 1, 1), p2(n + 1, 1);
        vector<long long> h1(n + 1, 0), h2(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            p1[i + 1] = (p1[i] * BASE1) % MOD1;
            p2[i + 1] = (p2[i] * BASE2) % MOD2;
            h1[i + 1] = (h1[i] * BASE1 + nums[i]) % MOD1;
            h2[i + 1] = (h2[i] * BASE2 + nums[i]) % MOD2;
        }

        auto check = [&](int len) -> bool {
            int count = n - len + 1;
            vector<uint64_t> hashes;
            hashes.reserve(count);

            for (int i = 0; i <= n - len; ++i) {
                long long v1 = (h1[i + len] - (h1[i] * p1[len]) % MOD1 + MOD1) % MOD1;
                long long v2 = (h2[i + len] - (h2[i] * p2[len]) % MOD2 + MOD2) % MOD2;
                hashes.push_back((static_cast<uint64_t>(v1) << 32) | static_cast<uint64_t>(v2));
            }

            sort(hashes.begin(), hashes.end());

            for (int i = 0; i < count; ++i) {
                bool left_diff = (i == 0) || (hashes[i] != hashes[i - 1]);
                bool right_diff = (i == count - 1) || (hashes[i] != hashes[i + 1]);
                if (left_diff && right_diff) {
                    return true;
                }
            }
            return false;
        };

        int low = 1, high = n, ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (check(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
