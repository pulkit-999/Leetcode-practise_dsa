/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) 
    {
        queue<Node*>q;
        
        vector<vector<int>>ans;
        q.push(root);
        if(root==NULL)
            return ans;
       
        while(!q.empty())
        {
             vector<int>v;
            int size=q.size();
            while(size--)
            {
               auto p=q.front();
            q.pop();
           
                v.push_back(p->val);
                for(auto x:p->children)
            {
                    //v.push_back(x->val);
            q.push(x);
        }
               
                
    }
             ans.push_back(v);
        }
        return ans;
    }
};