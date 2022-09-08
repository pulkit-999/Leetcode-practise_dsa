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
    int widthOfBinaryTree(TreeNode* root) 
    {
        queue<pair<TreeNode*,long long int>>q;
        q.push({root,0});
        long long int ans=0;
        while(!q.empty())
        {
            int size=q.size();
            int mini=q.front().second;
             int first,last;

            for(int i=0;i<size;i++)
            {
                long long int cur=q.front().second-mini;
                TreeNode* node=q.front().first;
                           q.pop();
                if(i==0)
                    first=cur;
                if(i==size-1)
                    last=cur;
                if(node->left)
                {
                q.push({node->left,cur*2+1});
                    }
                if(node->right)
                {
                    q.push({node->right,cur*2+2});
                }
                 
            }
           ans=max((int)ans,last-first+1);
        }
        return ans;
    }
};