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
    TreeNode* formTree(vector<int>& inorder, vector<int>& postorder,int &postindex,int is,int ie)
    {
        if(is>ie)
            return NULL;
        
        TreeNode* root=new TreeNode(postorder[postindex]);
        postindex--;

        
        int in_dex;
        for(int i=is;i<=ie;i++)
        {
            if(inorder[i]==root->val)
            {
                in_dex=i;
                break;
            }
        }
        root->right=formTree(inorder,postorder,postindex,in_dex+1,ie);
        root->left=formTree(inorder,postorder,postindex,is,in_dex-1);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postindex=postorder.size()-1;
        int is=0,ie=inorder.size()-1;
        return formTree(inorder,postorder,postindex,is,ie);
        
    }
};