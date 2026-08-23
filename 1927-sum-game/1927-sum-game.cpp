class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int half = n / 2;

        int diff = 0;
        int leftQ = 0, rightQ = 0;

        for (int i = 0; i < half; ++i) {
            if (num[i] == '?')
                leftQ++;
            else
                diff += num[i] - '0';
        }

        for (int i = half; i < n; ++i) {
            if (num[i] == '?')
                rightQ++;
            else
                diff -= num[i] - '0';
        }

        // If the number of '?' is equal on both sides,
        // Bob can force equality exactly when the current
        // difference is zero.
        if (leftQ == rightQ)
            return diff != 0;

        // Alice wins if the imbalance in '?' positions is
        // large enough to make equality impossible.
        int qDiff = abs(leftQ - rightQ);

        // Each unmatched '?' can contribute at most 9.
        // Bob can compensate for the known difference only
        // within the range created by the paired moves.
        if (qDiff % 2 == 1)
            return true;

        int required = qDiff / 2 * 9;

        if (leftQ > rightQ)
            diff += required;
        else
            diff -= required;

        return diff != 0;
    }
};