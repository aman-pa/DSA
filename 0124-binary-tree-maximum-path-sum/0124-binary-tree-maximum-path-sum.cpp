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
    int ans=INT_MIN;
    int s=0;
    int helper(TreeNode* root){
     if(root==NULL)return 0;
        int l=helper(root->left);
        int r=helper(root->right);
        l = max(0, l);
        r = max(0, r);
        ans=max(ans,root->val + l+r);
        return root->val + max(l, r);}

    int maxPathSum(TreeNode* root) {
        helper(root);
        return ans;
       
    }
};