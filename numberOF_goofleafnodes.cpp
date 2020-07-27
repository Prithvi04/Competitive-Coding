https://leetcode.com/contest/weekly-contest-199/problems/number-of-good-leaf-nodes-pairs/

//The approach is basically to return vector of distaces of all leaves from any root of a subtree,as an optimization we can ignore those distances
//which exceeds the threshold.
// if sum (+) of two distnces are <= threshold then increment the count.
//maintanin the count as global or as reference, finally return after all operations.

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
    int res=0;
    vector<int> help(int d,TreeNode* root)
    {
        if(!root)
            return {0};
        if(root->left==NULL && root->right==NULL)
            return {1};
        auto l=help(d,root->left);
        auto r=help(d,root->right);
        for(auto u:l)
        {
            for(auto v:r)
            {
                if((u&&v)&& u+v<=d)res++;
            }
        }
        vector<int>vec;
        for(auto u:l)
        {
            if(u&& u+1<d)
                vec.push_back(u+1);
        }
        for(auto v:r)
        {
            if(v && v+1<d)
                vec.push_back(v+1);
        }
        return vec;
    }
    int countPairs(TreeNode* root, int distance) {
        help(distance,root);
        return res;
    }
};