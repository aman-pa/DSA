class Solution {
public:
    map<int, set<int>> mpp;

    bool available(int row, int seat) {
        return mpp[row].count(seat) == 0;
    }

    int maxNumberOfFamilies(int n, vector<vector<int>>& rs) {
        int k = rs.size();

        for (int i = 0; i < k; i++) {
            mpp[rs[i][0]].insert(rs[i][1]);
        }

        int s = mpp.size();

        int emptyseat = (n - s) * 2;

        int ans = 0;
        ans += emptyseat;

        for (auto row : mpp) {

            bool a = available(row.first, 2) &&
                     available(row.first, 3) &&
                     available(row.first, 4) &&
                     available(row.first, 5);

            bool b = available(row.first, 4) &&
                     available(row.first, 5) &&
                     available(row.first, 6) &&
                     available(row.first, 7);

            bool c = available(row.first, 6) &&
                     available(row.first, 7) &&
                     available(row.first, 8) &&
                     available(row.first, 9);

            if (a && c)
                ans += 2;
            else if (a || b || c)
                ans += 1;
        }

        return ans;
    }
};