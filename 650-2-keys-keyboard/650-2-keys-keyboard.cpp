class Solution {
public:
    // int solve(int step,int value,int copy,int n,vector<vector<int>>&dp)
//     {
//         if(step>n||value>n)
//         {
//             return 1e9;
//         }
//         if(value==n)
//             return step;
//         if(dp[step][value]!=-1)
//             return dp[step][value];
//     return dp[step][value] =min(solve(step+1,copy+value,copy,n,dp),solve(step+2,2*value,value,n,dp));
         
//     }
    int minSteps(int n) 
    {
        int res = 0;
        for (int i = 2; i <= n / i; i++) {
            while (n % i == 0) {
                n /= i;
                res += i;
            }
        }
        
        if (n > 1) res += n;
        return res;
    }
};