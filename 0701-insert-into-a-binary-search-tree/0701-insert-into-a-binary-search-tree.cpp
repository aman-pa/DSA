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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node=new TreeNode(val);
        TreeNode* prev;
        if(root==NULL)return node;
        TreeNode* ans=root;
       while(root!=NULL){
         prev=root;
        if(root->val>val){
            root=root->left;
        }
        else if(root->val<val){
            root=root->right;
        }
       
      
       }
       if((prev->val)>val)prev->left=node;
       else prev->right=node;
       return ans;

    }
};