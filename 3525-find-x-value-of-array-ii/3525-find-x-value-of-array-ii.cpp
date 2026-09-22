class Solution {
public:
    struct Node {
        int prod = 1;
        int cnt[5] = {};
        int l = 0, r = 0;
    };

    int k;
    vector<Node> tree;

    Node merge(Node a, Node b) {
        Node c;
        c.prod = (a.prod * b.prod) % k;

        for (int i = 0; i < k; i++)
            c.cnt[i] = a.cnt[i];

        for (int i = 0; i < k; i++)
            c.cnt[(a.prod * i) % k] += b.cnt[i];

        return c;
    }

    void build(int u, int l, int r, vector<int>& nums) {
        tree[u].l = l;
        tree[u].r = r;

        if (l == r) {
            int v = nums[l] % k;
            tree[u].prod = v;
            tree[u].cnt[v] = 1;
            return;
        }

        int mid = (l + r) / 2;

        build(u * 2, l, mid, nums);
        build(u * 2 + 1, mid + 1, r, nums);

        tree[u] = merge(tree[u * 2], tree[u * 2 + 1]);
        tree[u].l = l;
        tree[u].r = r;
    }

    void update(int u, int pos, int val) {
        if (tree[u].l == tree[u].r) {
            val %= k;

            tree[u].prod = val;
            memset(tree[u].cnt, 0, sizeof(tree[u].cnt));
            tree[u].cnt[val] = 1;
            return;
        }

        int mid = (tree[u].l + tree[u].r) / 2;

        if (pos <= mid)
            update(u * 2, pos, val);
        else
            update(u * 2 + 1, pos, val);

        int l = tree[u].l;
        int r = tree[u].r;

        tree[u] = merge(tree[u * 2], tree[u * 2 + 1]);
        tree[u].l = l;
        tree[u].r = r;
    }

    Node query(int u, int ql, int qr) {
        if (ql <= tree[u].l && tree[u].r <= qr)
            return tree[u];

        int mid = (tree[u].l + tree[u].r) / 2;

        if (qr <= mid)
            return query(u * 2, ql, qr);

        if (ql > mid)
            return query(u * 2 + 1, ql, qr);

        Node a = query(u * 2, ql, qr);
        Node b = query(u * 2 + 1, ql, qr);

        return merge(a, b);
    }

    vector<int> resultArray(vector<int>& nums, int k,
                            vector<vector<int>>& queries) {
        this->k = k;

        int n = nums.size();
        tree.resize(4 * n + 5);

        build(1, 0, n - 1, nums);

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            update(1, index, value);

            Node res = query(1, start, n - 1);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};