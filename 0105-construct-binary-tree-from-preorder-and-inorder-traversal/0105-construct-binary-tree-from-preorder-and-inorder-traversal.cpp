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
    int search(vector<int>&inorder,int l,int r,int pre){
        for(int i=0;i<=r;i++){
            if(inorder[i]==pre)return i;
        }
        return -1;
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int &pre,int l,int r){
        if(l>r)return NULL;
        TreeNode* root=new TreeNode(preorder[pre]);
        int ll=search(inorder,l,r,preorder[pre]);
        pre++;
        root->left=helper(preorder,inorder,pre,l,ll-1);
        root->right=helper(preorder ,inorder,pre,ll+1,r);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int r=inorder.size();
        int pre=0;
        return helper(preorder,inorder,pre,0,r-1);

    }
};