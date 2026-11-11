class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans = 1LL * need1 * cost1 + 1LL * need2 * cost2;

        long long x = min(need1, need2);

        ans = min(ans, 1LL * x * costBoth +
                       1LL * (need1 - x) * cost1 +
                       1LL * (need2 - x) * cost2);

        ans = min(ans, 1LL * max(need1, need2) * costBoth);

        return ans;
    }
};