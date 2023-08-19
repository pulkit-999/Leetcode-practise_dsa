class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>indegree(n);
        vector<vector<int>>adj(n,vector<int>(n,0));
        for(auto x:roads)
        {
            indegree[x[0]]++;
            indegree[x[1]]++;
            adj[x[0]][x[1]]=1;
            adj[x[1]][x[0]]=1;
        }
        int maxi=0;
     int sum=0;
        for(int i=0;i<n;i++)
        {
           
            for(int j=0;j<n;j++)
            {
                sum=0;
                if(i!=j)
                {
                     sum=indegree[i]+indegree[j]-adj[i][j];
                    maxi=max(maxi,sum);
                }
            }
        }
        return maxi;
        

    }
};