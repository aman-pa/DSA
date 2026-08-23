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
    TreeNode* helper(vector<int>&nums,int s,int e){
        int m=s+(e-s)/2;
        if(s>e)return NULL;
        TreeNode* root=new TreeNode(nums[m]);
       root->left= helper(nums,s,m-1);
        root->right=helper(nums,m+1,e);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int s=0,e=nums.size();
        return helper(nums,s,e-1);
    }
};