class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int minPrice = INT_MAX;

        vector<int> freq(n + 1, 0);

        for (auto& item : items) {
            freq[item[0]]++;
            minPrice = min(minPrice, item[1]);
        }

        vector<int> multiples(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                multiples[i] += freq[j];
            }
        }

        map<int, long long> valid;

        for (auto& item : items) {
            int factor = item[0];
            int price = item[1];

            if (price < 2LL * minPrice) {
                valid[price] += multiples[factor] - 1;
            }
        }

        long long ans = 0;
        long long remaining = budget;

        for (auto& [price, count] : valid) {
            long long buy = min(count, remaining / price);

            ans += 2 * buy;
            remaining -= buy * price;
        }

        ans += remaining / minPrice;

        return (int)ans;
    }
};