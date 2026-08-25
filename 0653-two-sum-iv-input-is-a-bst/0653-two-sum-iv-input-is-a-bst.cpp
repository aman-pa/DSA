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
    void helper(TreeNode* root,int k){
         if(root==NULL)return ;
        findTarget(root->left,k);
        ans.push_back(root->val);
        findTarget(root->right,k);
    }
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL)return true;
       helper(root,k);
       int s=0,e=ans.size()-1;
       if(ans.size()==1)return false;
       while(s<e){
        int sum=ans[s]+ans[e];
        if(sum==k)return true;
        if(sum>k)e--;
        else s++;
       }
       return false;
    }
};