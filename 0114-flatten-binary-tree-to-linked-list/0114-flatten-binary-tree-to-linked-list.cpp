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
    vector<int>ans;
    void flatten(TreeNode* root) {
        if(root==NULL)return ;
        ans.push_back(root->val);
        flatten(root->left);
        flatten(root->right);
        TreeNode* tree=root;
        TreeNode* k=root;
        for(int i=1;i<ans.size();i++){
            TreeNode* a=new TreeNode(ans[i]);
            tree->right=a;
            tree->left=NULL;
            tree=tree->right;
        }
        root=tree;
    }
};