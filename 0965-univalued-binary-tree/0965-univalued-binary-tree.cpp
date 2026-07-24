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
    bool helper(TreeNode* root,int k){
         if(root==NULL)return true;
        if(k!=root->val)return false;
        bool left=helper(root->left,k);
        bool right=helper(root->right,k);
        return left&&right;
      
    }

    bool isUnivalTree(TreeNode* root) {
        if(root==NULL)return true;
        return helper(root,root->val);
       
        
    }
};