class Solution {
public:
    string lexGreaterPermutation(string s, string target) {

        vector<int> fre(26, 0);

        // Store frequency of characters in s
        for (char ch : s) {
            fre[ch - 'a']++;
        }

        string ans;

        // Try to build ans equal to target
        for (int i = 0; i < target.size(); i++) {

            char ch = target[i];

            // If current target character is available,
            // use it and continue
            if (fre[ch - 'a'] > 0) {
                ans.push_back(ch);
                fre[ch - 'a']--;
                continue;
            }

            // Current character is not available,
            // so try to find a bigger character
            int idx = ch - 'a' + 1;

            for (; idx < 26; idx++) {

                if (fre[idx] > 0) {

                    // Use the smallest bigger character
                    fre[idx]--;
                    ans.push_back((char)(idx + 'a'));

                    // Once ans is bigger than target,
                    // put all remaining characters in ascending order
                    for (int j = 0; j < 26; j++) {
                        ans.append(fre[j], (char)(j + 'a'));
                    }

                    return ans;
                }
            }

            // Could not find a bigger character,
            // so go back and change an earlier position
            while (ans.size() > 0) {

                int last_idx = ans.size() - 1;
                int last_char = ans.back();

                // Remove the last character from ans
                ans.pop_back();

                // Return that character to frequency array
                fre[last_char - 'a']++;

                // Try to find a character bigger than
                // target[last_idx]
                idx = target[last_idx] - 'a' + 1;

                for (; idx < 26; idx++) {

                    if (fre[idx] > 0) {

                        // Use the bigger character
                        fre[idx]--;
                        ans.push_back((char)(idx + 'a'));

                        // Fill remaining characters
                        // in ascending order
                        for (int j = 0; j < 26; j++) {
                            ans.append(fre[j], (char)(j + 'a'));
                        }

                        return ans;
                    }
                }
            }

            return "";
        }

        // We created ans equal to target.
        // Therefore, go backwards and try to make
        // an earlier character bigger.
        while (ans.size() > 0) {

            int last_idx = ans.size() - 1;
            int last_char = ans.back();

            // Remove last character
            ans.pop_back();

            // Restore it to frequency array
            fre[last_char - 'a']++;

            // Look for a character bigger than
            // target[last_idx]
            int idx = target[last_idx] - 'a' + 1;

            for (; idx < 26; idx++) {

                if (fre[idx] > 0) {

                    // Use the bigger character
                    fre[idx]--;
                    ans.push_back((char)(idx + 'a'));

                    // Fill remaining characters
                    // in ascending order
                    for (int j = 0; j < 26; j++) {
                        ans.append(fre[j], (char)(j + 'a'));
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};