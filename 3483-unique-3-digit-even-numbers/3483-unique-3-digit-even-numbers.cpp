class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int ans = 0;

        for (int num = 100; num <= 998; num += 2) {
            int temp = num;

            int a = temp / 100;
            int b = (temp / 10) % 10;
            int c = temp % 10;

            vector<int> count(10, 0);

            for (int d : digits) {
                count[d]++;
            }

            if (count[a] > 0) {
                count[a]--;

                if (count[b] > 0) {
                    count[b]--;

                    if (count[c] > 0) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};