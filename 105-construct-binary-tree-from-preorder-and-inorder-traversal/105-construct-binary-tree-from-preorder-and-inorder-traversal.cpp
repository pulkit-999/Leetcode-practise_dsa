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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        map<int,int>m;
        for(int i=0;i<inorder.size();i++)
        {
            m[inorder[i]]=i;
        }
         TreeNode* root=help( preorder,inorder,0,preorder.size()-1,0,inorder.size()-1,m);
        return root;
    }
    TreeNode* help(vector<int>& preorder, vector<int>& inorder,int prestart,int prend,int instart,int inend,map<int,int>&m)
    { if(prestart>prend ||instart>inend)
            return NULL;
        TreeNode* root=new TreeNode(preorder[prestart]);
       
        int inroot=m[root->val];
        int left=inroot-instart;
        root->left=help( preorder,inorder,prestart+1,prestart+left,instart,inroot-1,m);
        root->right=help( preorder,inorder,prestart+left+1,prend,inroot+1,inend,m);
        return root;
    }
};