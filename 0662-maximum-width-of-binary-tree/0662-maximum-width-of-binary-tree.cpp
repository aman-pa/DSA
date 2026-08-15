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
    int widthOfBinaryTree(TreeNode* root) {
        int m=0;
        queue<pair<TreeNode*,unsigned long long>>q;
        q.push({root,0});
        while(!q.empty()){
           unsigned long long s=q.size();
          unsigned  long f=q.front().second;
                int l=q.back().second;
                  m=max(m,(int)(l-f+1));
            for(int i=0;i<s;i++){
                auto node=q.front();

                if(node.first->left!=NULL)q.push({node.first->left,2*node.second+1});
                if(node.first->right!=NULL)q.push({node.first->right,2*node.second+2});
                q.pop();
              
            }
        }
        return m;
    }
};