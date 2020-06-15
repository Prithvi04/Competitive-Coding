/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxsum=0;
    void maxpath(TreeNode* root,int sum)
    {
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL && sum+root->val>maxsum)
        {
            maxsum=sum+root->val;
            return;
        }
        
        maxpath(root->left,sum+root->val);
        maxpath(root->right,sum+root->val);
        
        
    }
    int maxPathSum(TreeNode* root) {
        maxpath(root,0);
        
        return maxsum;
        
    }
};