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
    void helper(TreeNode* root, TreeNode* target,unordered_map<TreeNode*,TreeNode*>&par)
    {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* cur=q.front();
            q.pop();
            if(cur->left!=NULL)
            {
                par[cur->left]=cur;
                q.push(cur->left);
                
            }
               if(cur->right!=NULL)
            {
                par[cur->right]=cur;
                    q.push(cur->right);
                
            }
            
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
            queue<TreeNode* >q;
        
             unordered_map<TreeNode*,TreeNode*>par;
            unordered_map<TreeNode*,int>vis;
        helper(root,target,par);
        vis[target]=1;
        int level=0;
        q.push(target);
        
        while(!q.empty())
        {
            
        int size=q.size();
            if(level++ ==k)
                break;
            for(int i=0;i<size;i++)
            {
                TreeNode* current=q.front();
                q.pop();
                if(current->left!=NULL && !vis[current->left])
                {
                    q.push(current->left);
                    vis[current->left]=1;
                    
                }
                if(current->right!=NULL && !vis[current->right])
                {
                    q.push(current->right);
                    vis[current->right]=1;
                    
                }
                
                if(par[current]  && !vis[par[current]])
                {
                    q.push(par[current]);
                        vis[par[current]]=1;
                }
            }
        }
        vector<int>ans;
        while(!q.empty())
        {
            TreeNode* c=q.front();
            q.pop();
            ans.push_back(c->val);
        }
        return ans;
    }
};