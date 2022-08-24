class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_set<int>c;
    for(auto x:edges)
    {
        c.insert(x[0]);
        c.insert(x[1]);
    }
    int n=c.size();
    int ans=0;
vector<int>indegree(n+1,0);
vector<int>outdegree(n+1,0);
for(int i=0;i<edges.size();i++)
{
    indegree[edges[i][1]]++;
    outdegree[edges[i][0]]++;
}
int maxi=0;
for(int i=1;i<=n;i++)
{
    if(indegree[i]+outdegree[i]>maxi)
    {
        maxi=indegree[i]+outdegree[i];
        ans=i;
    }
    
}
return ans;
    }
};