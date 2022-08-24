class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<vector<int>>&ans,vector<int>&ds,int src,int target,vector<int>&vis)
    {
        vis[src]=true;
        ds.push_back(src);
        if(src==target)
        {
            ans.push_back(ds);
            }
        else for (auto x:graph[src])
        {
            
             dfs(graph,ans,ds,x,graph.size()-1,vis);
        }
        ds.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        vector<vector<int>>ans;
        vector<int>ds;
        int n=graph.size();
        vector<int>vis(n,0);
    dfs(graph,ans,ds,0,n-1,vis); 
        return ans;
    }
};