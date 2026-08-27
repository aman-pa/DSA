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
    vector<int>inorder;
    void helper(TreeNode* root){
        if(root==NULL)return;
        helper(root->left);
        inorder.push_back(root->val);
        helper(root->right);
    }
    int k=0;
    void compare(TreeNode* root){
        if(root==NULL)return ;
        compare(root->left);
        if(root->val!=inorder[k])root->val=inorder[k];
        k++;
        compare(root->right);
    }
    void recoverTree(TreeNode* root) {
        TreeNode* temp=root;
        helper(root);
        sort(inorder.begin(),inorder.end());
        TreeNode* ans=new TreeNode(inorder[0]);
        compare(root);
        root=ans;
    }
};