/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
unordered_map<int,int>mpp;
vector<int>ans;
    void dfs(TreeNode* root) {
    if (root == NULL) return;

    mpp[root->val]++;
    dfs(root->left);
    dfs(root->right);
}
    vector<int> findMode(TreeNode* root) {
    dfs(root);

    int m = -1;
    for (auto it : mpp)
        m = max(m, it.second);

    for (auto it : mpp)
        if (it.second == m)
            ans.push_back(it.first);

    return ans;
}
};