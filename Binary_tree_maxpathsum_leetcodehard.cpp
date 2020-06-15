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
    int maxPathSum(TreeNode* root) {
        if(root==NULL)
            return 0;
        queue<TreeNode *>q;
        q.push(root);
        int res=INT_MIN;
        while(q.empty()==false)
        {
            int count=q.size();
            for(int i=0;i<count;i++)
            {
                TreeNode *curr=q.front();
                q.pop();
                int sum=curr->val;
                res=max(res,sum);
                int sum1=sum;
                if(curr->left!=NULL)
                {
                    sum+=curr->left->val;
                    q.push(curr->left);
                    res=max(res,sum);
                }
                if(curr->right!=NULL)
                {
                    sum+=curr->right->val;
                    sum1+=curr->right->val;
                    q.push(curr->right);
                    res=max(res,sum);
                    res=max(res,sum1);
                }
                
               
            }
        }
        return res;
        
    }
};