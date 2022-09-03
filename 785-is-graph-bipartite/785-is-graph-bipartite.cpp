class Solution {
public:
    bool bfs(vector<vector<int>>& graph,int src,vector<int>&vis)
    {
        queue<int>q;
        q.push(src);
        vis[src]=1;
        while(!q.empty())
        {
            int el=q.front();
            q.pop();
            for(auto it:graph[el])
            {
             if(vis[it]==-1)
             {
                 vis[it]=1-vis[el];
                 q.push(it);
                 
             }
                else if (vis[it]==vis[el])
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        //vector<int>grap[n];
        vector<int>vis(n,-1);
        // for(auto it:graph)
        // {
        //     for(auto x:it)
        //     {
        //         if(x!=it[0])
        //     grap[it[0]].push_back(x);
        //     }
        // }
        for(int i=0;i<n;i++)
        {
            if(vis[i]==-1)
            {
            if(!bfs(graph,i,vis))
                return false;
            }
        }
        return true;
        
    }
};