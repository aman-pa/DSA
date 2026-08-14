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
    int leftheight(TreeNode* l){
        int k=0;
        while(l){
            k++;
           l=l->left;
        }
        return k;
    }
     int rightheight(TreeNode* l){
        int k=0;
        while(l){
            k++;
            l=l->right;
        }
        return k;
    }


    int countNodes(TreeNode* root) {
        if(root==NULL)return 0;
        int l=leftheight(root->left);
        int r=rightheight(root->right);
        if(l==r) return pow(2,l+1)-1;
        else return 1+countNodes(root->left)+countNodes(root->right);
    }
};