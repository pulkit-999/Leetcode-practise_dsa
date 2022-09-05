class Solution {
public:
    const int mod=1e9+7;
    bool check(vector<vector<int>>& grid,int i,int j)
    {
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size())
            return false;
        return true;
    }
    int solve(vector<vector<int>>& grid,vector<vector<int>>& dp,int i,int j)
    {
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int dx[4]={0,1,-1,0};
        int dy[4]={-1,0,0,1};
        int res=1;
        for(int k=0;k<4;k++)
        {
            int x=dx[k]+i;
            int y=dy[k]+j;
            if(check(grid,x,y))
            {
                if(grid[x][y]>grid[i][j])
              res+=solve(grid,dp,x,y);
                res=res%mod;
            }
        }
        return dp[i][j]=res;
    }
    int countPaths(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans+=solve(grid,dp,i,j);
                ans=ans%mod;
            }
        }
        return ans%mod;
    }
};