class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int mn = INT_MAX;

        for (int x : nums) {
            mn = min(mn, abs(x));
        }

        for (int i = 0; i < n && k > 0; i++) {
            if (nums[i] < 0) {
                nums[i] *= -1;
                k--;
            } else {
                break;
            }
        }

        long long sum = 0;

        for (int x : nums) {
            sum += x;
        }

        if (k % 2 != 0) {
            sum -= 2LL * mn;
        }

        return sum;
    }
};