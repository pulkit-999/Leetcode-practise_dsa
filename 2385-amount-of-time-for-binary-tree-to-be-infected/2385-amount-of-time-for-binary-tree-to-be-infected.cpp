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
    int maxi(map<TreeNode*,TreeNode*>&m,TreeNode*target)
    {
     map<TreeNode*,int>vis;
        queue<TreeNode*>q;
        q.push(target);
        vis[target]=1;
        int ans=0;
        while(!q.empty())
        {
            int size=q.size();
            int flag=0;
            for(int i=0;i<size;i++)
            {
            auto node=q.front();
            q.pop();
            if(node->left &&!vis[node->left])
            {
                vis[node->left]=1;
                q.push(node->left);
                flag=1;
            }
                 if(node->right &&!vis[node->right])
            {
                vis[node->right]=1;
                q.push(node->right);
                flag=1;
            }
                if(m[node]&& !vis[m[node]])
                {
                    q.push(m[node]);
                    vis[m[node]]=1;
                    flag=1;
                }
            }
            if(flag)
                ans++;
        }
        return ans;
    }
    TreeNode* parent(TreeNode* root,map<TreeNode*,TreeNode*>&m,int start)
    {
        TreeNode* res;
        queue<TreeNode* >q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            if(node->val==start)
                res=node;
            if(node->left)
            {
                m[node->left]=node;
                q.push(node->left);
            }
            if(node->right)
            {
                m[node->right]=node;
                q.push(node->right);
            }
        }
        return res;
    }
    int amountOfTime(TreeNode* root, int start)
    {
        map<TreeNode*,TreeNode*>m;
        TreeNode* target=parent(root,m,start);
        int k=maxi(m,target);
        return k;
        
    }
};