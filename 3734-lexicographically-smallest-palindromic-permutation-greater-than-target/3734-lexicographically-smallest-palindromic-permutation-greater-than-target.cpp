class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {

        int n = s.size();

        // Count frequency of every character
        vector<int> cnt(26, 0);

        for (char c : s) {
            cnt[c - 'a']++;
        }

        // Check whether a palindrome can be formed
        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2 == 1) {
                odd++;
                mid = char('a' + i);
            }
        }

        if (odd > 1) {
            return "";
        }

        int halfLen = n / 2;

        // Special case: length 1
        if (n == 1) {
            string ans = string(1, s[0]);
            return ans > target ? ans : "";
        }

        // Frequency of characters available for the left half
        vector<int> half(26);

        for (int i = 0; i < 26; i++) {
            half[i] = cnt[i] / 2;
        }

        // Try to make the left half exactly equal to target's left half
        bool same = true;

        for (int i = 0; i < halfLen; i++) {

            int x = target[i] - 'a';

            if (half[x] == 0) {
                same = false;
                break;
            }

            half[x]--;
        }

        if (same) {

            string left = target.substr(0, halfLen);

            string ans = left;

            // Add middle character if length is odd
            if (n % 2 == 1) {
                ans += mid;
            }

            // Add reverse of left half
            string rev = left;
            reverse(rev.begin(), rev.end());

            ans += rev;

            // Exact palindrome is valid only if it is
            // strictly greater than target
            if (ans > target) {
                return ans;
            }
        }

        // Try to increase the rightmost possible position
        // of the left half
        for (int i = halfLen - 1; i >= 0; i--) {

            // Reset half frequencies
            for (int j = 0; j < 26; j++) {
                half[j] = cnt[j] / 2;
            }

            // Match target[0 ... i-1]
            bool possible = true;

            for (int j = 0; j < i; j++) {

                int x = target[j] - 'a';

                if (half[x] == 0) {
                    possible = false;
                    break;
                }

                half[x]--;
            }

            if (!possible) {
                continue;
            }

            int current = target[i] - 'a';

            // Try the smallest character greater than target[i]
            for (int next = current + 1; next < 26; next++) {

                if (half[next] == 0) {
                    continue;
                }

                half[next]--;

                string left = "";

                // Keep prefix same as target
                left += target.substr(0, i);

                // Make current position greater
                left += char('a' + next);

                // Fill remaining left-half characters
                // in ascending order
                for (int c = 0; c < 26; c++) {
                    while (half[c] > 0) {
                        left += char('a' + c);
                        half[c]--;
                    }
                }

                // Construct the complete palindrome
                string ans = left;

                // Add middle character if length is odd
                if (n % 2 == 1) {
                    ans += mid;
                }

                // Add reverse of left half
                string rev = left;
                reverse(rev.begin(), rev.end());

                ans += rev;

                return ans;
            }
        }

        return "";
    }
};