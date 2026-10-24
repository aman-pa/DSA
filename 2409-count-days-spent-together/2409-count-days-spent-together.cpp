class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int a1 = stoi(arriveAlice.substr(0, 2));
        int a2 = stoi(arriveAlice.substr(3, 2));

        int l1 = stoi(leaveAlice.substr(0, 2));
        int l2 = stoi(leaveAlice.substr(3, 2));

        int b1 = stoi(arriveBob.substr(0, 2));
        int b2 = stoi(arriveBob.substr(3, 2));

        int bl1 = stoi(leaveBob.substr(0, 2));
        int bl2 = stoi(leaveBob.substr(3, 2));

        int aliceStart = a2;
        int aliceEnd = l2;
        int bobStart = b2;
        int bobEnd = bl2;

        for (int i = 0; i < a1 - 1; i++)
            aliceStart += days[i];

        for (int i = 0; i < l1 - 1; i++)
            aliceEnd += days[i];

        for (int i = 0; i < b1 - 1; i++)
            bobStart += days[i];

        for (int i = 0; i < bl1 - 1; i++)
            bobEnd += days[i];

        int start = max(aliceStart, bobStart);
        int end = min(aliceEnd, bobEnd);

        return max(0, end - start + 1);
    }
};