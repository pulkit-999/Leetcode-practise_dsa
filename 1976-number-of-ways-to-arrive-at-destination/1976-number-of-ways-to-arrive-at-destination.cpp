class Solution {
public:
    #define ll long long
    const int mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads)
    {
        vector<pair<ll ,ll>>graph[n];
        for(auto x:roads)
        {
            graph[x[0]].push_back({x[1],x[2]});
            graph[x[1]].push_back({x[0],x[2]});
        }
       
      
    vector<long long>dis(n,LONG_MAX),ways(n,0);
        ways[0]=1;
        dis[0]=0;
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
        pq.push({0,0});
        
        while(!pq.empty())
        {
            int prev=pq.top().second;
            auto dist=pq.top().first;
            pq.pop();
           
            for(auto it : graph[prev]){
                ll distt = dist + it.second;
                ll next = it.first;
                if(dis[next]>distt)
                {
                    ways[next]=ways[prev];
                    dis[next]=distt;
                    pq.push({dis[next],next});
                    
                }
                else if(distt==dis[next])
                {
                    ways[next]=(ways[next]%mod+ways[prev]%mod);
                }
            }
        }
        return ways[n-1]%mod;
    }
};