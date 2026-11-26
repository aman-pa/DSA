class Solution {
public:
    bool canAliceWin(int n) {
        int last = 10;
        int a = 1;

        while (n >= last) {
            n -= last;
            last--;

            a = 1 - a;
        }

        return a == 0;
    }
};