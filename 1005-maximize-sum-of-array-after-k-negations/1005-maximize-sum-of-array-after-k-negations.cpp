class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int p = INT_MAX;

        for(int i = 0; i < n; i++) {
            p = min(p, abs(nums[i]));
        }

        for(int i = 0; i < n; i++) {
            if(k > 0 && nums[i] < 0) {
                nums[i] *= -1;
                k--;
            }
            else {
                break;
            }
        }

        int s = 0;

        for(int x : nums) {
            s += x;
        }

        if(k % 2 != 0) {
            s -= 2 * p;
        }

        return s;
    }
};