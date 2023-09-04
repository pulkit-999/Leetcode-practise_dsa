class Solution {
public:
    int solve(vector<vector<int>>&dp,string &s1, string &s2, string &s3,int n,int m,int len)
    {
        if(len==0)
        return 1;
        if(dp[n][m]!=-1)
        return dp[n][m];
        int a=0,b=0;
        if(n-1>=0 and s1[n-1]==s3[len-1])
       a= solve(dp,s1,s2,s3,n-1,m,len-1);
        if(m-1>=0 and s2[m-1]==s3[len-1])
        b=solve(dp,s1,s2,s3,n,m-1,len-1);
    return dp[n][m]=a or b;
        }
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        int len=s3.size();
        if(n+m!=len)
        return false;
        return solve(dp,s1,s2,s3,n,m,len);
    }
};