class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int>degree(n,0);
        vector<int>adj[n];
        vector<int> ans;
        if(n==1)
        {
            return {0};
        }
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            degree[edges[i][1]]++;
             degree[edges[i][0]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(degree[i]==1)
            q.push(i);
        }
        while(n>2)
        {
            int sze=q.size();
            n-=sze;
            for(int i=0;i<sze;i++)
            {
                int k=q.front();
                q.pop();
                for(auto x:adj[k])
                {
                degree[x]--;
                if(degree[x]==1)
                q.push(x);
                }
            }
        }
        while(q.size())
        {
        ans.push_back(q.front());q.pop();
        }
        
        return ans;
    }
};