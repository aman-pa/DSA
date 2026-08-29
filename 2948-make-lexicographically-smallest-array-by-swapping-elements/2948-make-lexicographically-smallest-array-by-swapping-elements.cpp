class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {

        int n = nums.size();

        // Store {value, original index}
        vector<pair<int, int>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({nums[i], i});
        }

        // Sort by value
        sort(a.begin(), a.end());

        int i = 0;

        while (i < n) {

            // Find the current group
            int j = i;

            while (j + 1 < n &&
                   a[j + 1].first - a[j].first <= limit) {
                j++;
            }

            // Store original indices of this group
            vector<int> indices;

            for (int k = i; k <= j; k++) {
                indices.push_back(a[k].second);
            }

            // Sort original indices
            sort(indices.begin(), indices.end());

            // Values in a[i...j] are already sorted
            for (int k = 0; k < indices.size(); k++) {
                nums[indices[k]] = a[i + k].first;
            }

            // Move to next group
            i = j + 1;
        }

        return nums;
    }
};