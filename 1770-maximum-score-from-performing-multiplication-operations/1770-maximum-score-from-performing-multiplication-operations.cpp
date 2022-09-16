class Solution {
public:
    int solve(vector<vector<int>>&dp,vector<int>& nums, vector<int>& multipliers,int i,int j,int n)
    {
        if(j==multipliers.size())
            return 0;
        if(dp[i][j]!=-1e9)
            return dp[i][j];
        int front=solve(dp,nums,multipliers,i+1,j+1,n)+nums[i]*multipliers[j];
        int back=solve(dp,nums,multipliers,i,j+1,n-1)+nums[n]*multipliers[j];
        return dp[i][j]=max(front,back);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers)
    {
        int m=multipliers.size();
       vector<vector<int>>dp(m+1,vector<int>(m+1,-1e9));
       return solve(dp,nums,multipliers,0,0,nums.size()-1);
    }
};