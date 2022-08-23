class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>par(1001);
for(int i=0;i<1001;i++)
{
    par[i]=i;
}
vector<int>ans;
for (auto it:edges)
{
    int node_a=it[0];
    int node_b=it[1];
    int par_a=node_a;
    int par_b=node_b;
    while(par_a!=par[par_a])
    {
        par_a=par[par_a];
    }
     while(par_b!=par[par_b])
    {
        par_b=par[par_b];
    }
    if(par_a!=par_b)
    par[par_a]=par_b;
    else
    ans=it;
}
return ans;
}
        
        
        
    
};