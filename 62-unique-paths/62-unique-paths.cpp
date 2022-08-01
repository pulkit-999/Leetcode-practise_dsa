class Solution {

public:
    vector<vector<int>>dp;
    int path(int i,int j,int m,int n)
    {
        if(i>=m||j>=n)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(i==m-1&&j==n-1)
            return 1;
        return dp[i][j]=path(i+1,j,m,n)+path(i,j+1,m,n);
    }
    int uniquePaths(int m, int n) {
        dp.resize(m,vector<int>(n,-1));
        return path(0,0,m,n);
        
    }
};