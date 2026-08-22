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
    int search(vector<int>& inorder, vector<int>& postorder,int l,int r,int post){
        for(int i=l;i<=r;i++){
            if(inorder[i]==post)return i;
        }
        return -1;
    }
    TreeNode*  helper(vector<int>& inorder, vector<int>& postorder,int &post,int l,int r){
        if(l>r)return NULL;
        TreeNode* root=new TreeNode(postorder[post]);
        int idx=search(inorder,postorder,l,r,postorder[post]);
        post--;
        root->right=helper(inorder,postorder,post,idx+1,r);
        root->left=helper(inorder,postorder,post,l,idx-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int post=postorder.size()-1;
        int r=inorder.size();
        return helper(inorder,postorder,post,0,r-1);
    }
};