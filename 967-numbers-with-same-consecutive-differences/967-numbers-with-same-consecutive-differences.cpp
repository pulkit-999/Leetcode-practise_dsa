class Solution {
public:
    void dfs(int num,int n,vector<int>&ans,int k)
    {
        if(n==0)
        {
            ans.push_back(num);
            return ;
        }
        int dig=num%10;
        if(dig>=k)
            dfs(num*10+dig-k,n-1,ans,k);
        if(dig+k<10 && k>0)
            dfs(num*10+dig+k,n-1,ans,k);
        
    }
    vector<int> numsSameConsecDiff(int n, int k) 
    {
     int num=pow(10,n-1);
        vector<int>ans;
        for(int i=1;i<10;i++)
            dfs(i,n-1,ans,k);
        return ans;
    }
};