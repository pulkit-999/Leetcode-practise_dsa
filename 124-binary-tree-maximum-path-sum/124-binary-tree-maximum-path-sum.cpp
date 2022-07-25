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
    int help(TreeNode* root,int &maxi)
    {
        if(root==NULL)
            return 0;
        int left=max(0,help(root->left,maxi));
        int right=max(0,help(root->right,maxi));
        // if(right<0)
        //     right=0;
        // if(left<0)
        //     left=0;
        maxi=max(maxi,root->val+left+right);
        return root->val+max(left,right);
    }
    
    int maxPathSum(TreeNode* root) {
        int maxi=-1e9;
        if(root->left==NULL && root->right==NULL)
            return root->val;
        help(root,maxi);
        return maxi;
    }
};