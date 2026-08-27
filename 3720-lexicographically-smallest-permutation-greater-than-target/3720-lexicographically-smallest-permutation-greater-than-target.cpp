class Solution {
public:
    string lexGreaterPermutation(string s, string target) {

        // Store frequency of each character
        vector<int> fre(26, 0);

        for (char ch : s) {
            fre[ch - 'a']++;
        }

        string ans = "";

        // Try to match target from left to right
        for (int i = 0; i < target.size(); i++) {

            // Same character is available
            if (fre[target[i] - 'a'] > 0) {
                ans.push_back(target[i]);
                fre[target[i] - 'a']--;
            }

            else {
                // Same character is not available,
                // so try to find the smallest greater character
                int idx = target[i] - 'a' + 1;

                for (; idx < 26; idx++) {

                    if (fre[idx] > 0) {

                        // Once we choose a greater character,
                        // answer is already greater than target
                        ans.push_back(char(idx + 'a'));
                        fre[idx]--;

                        // Put remaining characters in ascending order
                        for (int j = 0; j < 26; j++) {
                            ans.append(fre[j], char(j + 'a'));
                        }

                        return ans;
                    }
                }

                // No greater character found at this position.
                // Stop forward matching and backtrack.
                break;
            }
        }

        // Backtrack from the last matched character
        while (ans.size() > 0) {

            int last_idx = ans.size() - 1;
            int last_char = ans.back();

            // Remove the last character from ans
            ans.pop_back();

            // Return it to the frequency array
            fre[last_char - 'a']++;

            // Try to put a character greater than target[last_idx]
            int idx = target[last_idx] - 'a' + 1;

            for (; idx < 26; idx++) {

                if (fre[idx] > 0) {

                    // Use the greater character
                    fre[idx]--;
                    ans.push_back(char(idx + 'a'));

                    // Fill remaining characters in ascending order
                    for (int j = 0; j < 26; j++) {
                        ans.append(fre[j], char(j + 'a'));
                    }

                    return ans;
                }
            }
        }

        // No permutation is greater than target
        return "";
    }
};