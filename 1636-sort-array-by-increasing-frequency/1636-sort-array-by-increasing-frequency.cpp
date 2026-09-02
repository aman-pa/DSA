class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> mpp;
        for (int x : nums) mpp[x]++;

        vector<pair<int, int>> freq;
        for (auto it : mpp) freq.push_back({it.second, it.first});

        sort(freq.begin(), freq.end(), [](pair<int, int>& a, pair<int, int>& b) {
            if (a.first == b.first)
                return a.second > b.second;
            return a.first < b.first;
        });

        vector<int> ans;

        for (auto it : freq) {
            for (int j = 0; j < it.first; j++)
                ans.push_back(it.second);
        }

        return ans;
    }
};