class Solution {
public:
    int solve(int step,int value,int copy,int n)
    {
        if(step>n||value>n)
        {
            return 1e9;
        }
        if(value==n)
            return step;
        return min(solve(step+1,copy+value,copy,n),solve(step+2,2*value,value,n));
    }
    int minSteps(int n) 
    {
        if(n==1)
            return 0;
    return solve(1,1,1,n);
    }
};