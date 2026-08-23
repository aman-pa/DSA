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
    int m=INT_MAX;
    vector<int>ans;
    int minDiffInBST(TreeNode* root) {
            if(root==NULL)return 0;
            if(root->left)
            minDiffInBST(root->left);
            ans.push_back(root->val);
            if(root->right)
            minDiffInBST(root->right);
            for(int i=0;i<ans.size()-1;i++){
                m=min(m,ans[i+1]-ans[i]);
            }
            return m;
          
        
    }
};