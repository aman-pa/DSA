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
// vector<int>ans;
// int m=INT_MAX;
int prev=-1;
int ans=INT_MAX;
    void inorder(TreeNode* root){
        if(root==NULL)return;
        inorder(root->left);
        if(prev!=-1)
        ans=min(ans,root->val-prev);
        prev=root->val;
        inorder(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        // if(root==NULL)return 0;
        // getMinimumDifference(root->left);
        // ans.push_back(root->val);
        // getMinimumDifference(root->right);
        // if(ans.size()==0)return 0;
        // for(int i=0;i<ans.size()-1;i++){
        //     int k=abs(ans[i+1]-ans[i]);
        //     m=min(m,k);
        // }
        // return m;
        inorder(root);
        return ans;

    }
};