class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int totalSum = 0;

        for (int num : nums) {
            totalSum += num;
        }

        if (x > totalSum) return -1;
        if (x == totalSum) return n;

        int target = totalSum - x;
        int l = 0, r = 0;
        int s = 0, len = -1;

        while (r < n) {
            s += nums[r];

            while (s > target) {
                s -= nums[l];
                l++;
            }

            if (s == target) {
                len = max(len, r - l + 1);
            }

            r++;
        }

        if (len == -1) return -1;

        return n - len;
    }
};