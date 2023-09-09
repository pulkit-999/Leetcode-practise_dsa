class Solution {
public:
int solve(int i,int j,vector<vector<int>>&dp,int &ans,vector<vector<char>>& matrix)
{
    if(i>=matrix.size() or j>=matrix[0].size())
    return 0;
    if(dp[i][j]!=-1)
    return dp[i][j];
    int right=solve(i,j+1,dp,ans,matrix);
    int diag=solve(i+1,j+1,dp,ans,matrix);
    int down=solve(i+1,j,dp,ans,matrix);
    if(matrix[i][j]=='1')
    {
    dp[i][j]=1+min({right,down,diag});
    ans=max(ans,dp[i][j]);
    return dp[i][j];
    }
    else return dp[i][j]=0;
   
}
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int ans=0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
         solve(0,0,dp,ans,matrix);
        return ans*ans;
    }
};