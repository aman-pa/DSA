class Solution {
public:
    set<string> parse(string &s, int &i) {
        set<string> res, cur;
        cur.insert("");

        while (i < s.size() && s[i] != '}') {
            if (s[i] == ',') {
                for (auto &x : cur) res.insert(x);
                cur.clear();
                cur.insert("");
                i++;
            } 
            else {
                set<string> part;

                if (s[i] == '{') {
                    i++;
                    part = parse(s, i);
                    i++;
                } 
                else {
                    part.insert(string(1, s[i]));
                    i++;
                }

                set<string> next;
                for (auto &a : cur)
                    for (auto &b : part)
                        next.insert(a + b);

                cur = next;
            }
        }

        for (auto &x : cur) res.insert(x);
        return res;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> ans = parse(expression, i);
        return vector<string>(ans.begin(), ans.end());
    }
};