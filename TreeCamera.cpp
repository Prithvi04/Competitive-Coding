Given a binary tree, we install cameras on the nodes of the tree. 

Each camera at a node can monitor its parent, itself, and its immediate children.

Calculate the minimum number of cameras needed to monitor all nodes of the tree.

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
    int Cam(TreeNode* root,int &count)
    {
        if(root==NULL)
            return -1; //no need camera camera
        int l=Cam(root->left,count);
        int r=Cam(root->right,count);
        
        if(l==1||r==1)//either of my childeren need a camera so i acquire camera
        {
            count++;
            return 0;
        }
        
        else if(l==0 ||r==0) //either of my child has a camera so i don't need a camera
            return -1;
        
        return 1; //neither of childern need camera but i do.
    }
    
    int minCameraCover(TreeNode* root) {
        if(root==NULL)
            return 0;
        int count=0;
        int ans=Cam(root,count);
        
        return ans==1?count+1:count; //edge case: when root itself needs a camera or not
        
    }
};