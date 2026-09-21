class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> curr(k, 0);

            int rem = num % k;

            // Subarray containing only current element
            curr[rem]++;

            // Extend previous subarrays
            for (int r = 0; r < k; r++) {
                int newRem = (1LL * r * rem) % k;
                curr[newRem] += dp[r];
            }

            // Add counts of all subarrays ending here
            for (int r = 0; r < k; r++) {
                result[r] += curr[r];
            }

            dp = curr;
        }

        return result;
    }
};