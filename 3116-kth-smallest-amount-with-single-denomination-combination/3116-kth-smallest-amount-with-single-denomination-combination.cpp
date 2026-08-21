class Solution {
public:
    long long count(long long mid, vector<int>& coins) {
        long long c = 0;
        int n = coins.size();

        for (int mask = 1; mask < (1 << n); mask++) {
            long long l = 1;
            int cnt = 0;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    long long g = gcd(l, (long long)coins[i]);

                    // Prevent LCM from becoming larger than mid
                    if (l > mid / (coins[i] / g)) {
                        l = mid + 1;
                        break;
                    }

                    l = l / g * coins[i];
                    cnt++;
                }
            }

            if (l > mid)
                continue;

            if (cnt % 2 == 1)
                c += mid / l;
            else
                c -= mid / l;
        }

        return c;
    }

    long long findKthSmallest(vector<int>& coins, int k) {
        int m = *min_element(coins.begin(), coins.end());

        long long low = m;
        long long high = 1LL * m * k;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            long long c = count(mid, coins);

            if (c < k)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return low;
    }
};