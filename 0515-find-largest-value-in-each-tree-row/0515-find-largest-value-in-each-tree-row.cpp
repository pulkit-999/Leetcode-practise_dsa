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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<int>res;
        if(root==NULL)
        return res;
        while(q.size())
        {
            long long maxi=-1e18;
            int n=q.size();
            while(n--)
            {
                auto k=q.front();
                q.pop();
                maxi=max(maxi,(long long)k->val);
                if(k->right)
                q.push(k->right);
                if(k->left)
                q.push(k->left);
            }
            res.push_back(maxi);
        }
        return res;
    }
};