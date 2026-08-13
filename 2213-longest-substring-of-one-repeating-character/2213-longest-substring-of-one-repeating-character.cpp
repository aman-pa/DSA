class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        int k = queryIndices.size();

        vector<int> ans;

        set<pair<int, int>> se;
        multiset<int> lengths;

        // Create initial runs
        int start = 0;

        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) {
                se.insert({start, i - 1});
                lengths.insert(i - start);
                start = i;
            }
        }

        se.insert({start, n - 1});
        lengths.insert(n - start);

        for (int q = 0; q < k; q++) {
            int p = queryIndices[q];
            char newChar = queryCharacters[q];

            // If character doesn't actually change
            if (s[p] == newChar) {
                ans.push_back(*lengths.rbegin());
                continue;
            }

            // Find run containing p
            auto it = se.upper_bound({p, n});

            if (it != se.begin())
                --it;

            int L = it->first;
            int R = it->second;

            // Remove old run
            lengths.erase(lengths.find(R - L + 1));
            se.erase(it);

            // Left part of old run
            if (L <= p - 1) {
                se.insert({L, p - 1});
                lengths.insert(p - L);
            }

            // Right part of old run
            if (p + 1 <= R) {
                se.insert({p + 1, R});
                lengths.insert(R - p);
            }

            s[p] = newChar;

            // New character as a single run
            int newL = p;
            int newR = p;

            // Check left neighbour
            auto rightIt = se.lower_bound({p, -1});

            if (rightIt != se.begin()) {
                auto leftIt = prev(rightIt);

                if (s[leftIt->second] == newChar) {
                    newL = leftIt->first;

                    lengths.erase(lengths.find(leftIt->second - leftIt->first + 1));
                    se.erase(leftIt);
                }
            }

            // Check right neighbour
            rightIt = se.lower_bound({p + 1, -1});

            if (rightIt != se.end()) {
                if (rightIt->first == p + 1 &&
                    s[rightIt->first] == newChar) {

                    newR = rightIt->second;

                    lengths.erase(lengths.find(rightIt->second - rightIt->first + 1));
                    se.erase(rightIt);
                }
            }

            se.insert({newL, newR});
            lengths.insert(newR - newL + 1);

            ans.push_back(*lengths.rbegin());
        }

        return ans;
    }
};