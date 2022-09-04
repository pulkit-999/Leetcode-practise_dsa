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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>m;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
            while(!q.empty())
            {
                TreeNode* node=q.front().first;
                int x=q.front().second.first;
                int y=q.front().second.second;
                q.pop();
                m[x][y].insert(node->val);
                if(node->left)
                {
                    q.push({node->left,{x-1,y+1}});
                }
                if(node->right)
                {
                    q.push({node->right,{x+1,y+1}});
                }
            }
        vector<vector<int>>ans;
        for(auto x:m)
        {
            vector<int>res;
            for(auto y:x.second)
            {
            res.insert(res.end(),y.second.begin(),y.second.end());
                }
            ans.push_back(res);
        }
        return ans;
    }
};