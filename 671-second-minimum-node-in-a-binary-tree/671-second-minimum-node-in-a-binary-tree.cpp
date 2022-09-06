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
    void helper(TreeNode* root,set<int>&s)
    {
        if(root==NULL)
            return ;
        s.insert(root->val);
        helper(root->left,s);
        helper(root->right,s);
        
    }
    int findSecondMinimumValue(TreeNode* root) {
        set<int>s;
        helper(root,s);
        int ans=0;
        int t=1;
        for(auto x:s)
        {
            if(t==2)
            {
            ans=x;
            break;
        }
            t++;
        }
        if(s.size()==1)
            return -1;
        return ans;
    }
};