class Solution {
public:
    bool check(vector<int>&lis,set<pair<int,int>>&se)
    {
        for(int i=0;i<lis.size();i++)
        {
            for(int j=i+1;j<lis.size();j++)
            {
                int a=min(lis[i],lis[j]);
                int b=max(lis[i],lis[j]);
                if(se.find({a,b})==se.end())
                return false;
            }
        }
        return true;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
    vector<int>adj[n];
    set<pair<int,int>>se;
    int res=0;
    for(auto x:edges)
    {
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
        se.insert({min(x[0],x[1]),max(x[0],x[1])});

    }
    vector<int>vis(n);
   queue<int>q;
    for(int i=0;i<n;i++)
    {
        if(vis[i])
        continue;
         
        q.push(i);
        vector<int>lis;
        vis[i]++;
        lis.push_back(i);
        while(q.size())
        {
            int k=q.front();
            q.pop();
            for(auto x:adj[k])
            {
                if(vis[x])
                continue;
                vis[x]=1;
                lis.push_back(x);
                q.push(x);
            }
        }
        if(check(lis,se))
        res++;
    }
    return res;

    }
};