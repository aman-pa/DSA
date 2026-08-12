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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        queue<TreeNode*>q;
        q.push(root);
        bool ltr=true;
        while(!q.empty()){
            vector<int>level;
            int s=q.size();
            for(int i=0;i<s;i++){
                TreeNode* node=q.front();
                level.push_back(node->val);
                if(node->left!=NULL)q.push(node->left);
                if(node->right!=NULL)q.push(node->right);
                 q.pop();
            }
            if(ltr){ans.push_back(level);ltr=false;}
            else{
               reverse(level.begin(),level.end());
                ans.push_back(level);
                ltr=true;
            }

        }
        return ans;
    }
};