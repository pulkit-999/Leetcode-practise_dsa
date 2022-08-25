class Solution {
public:
    #define ll long long
    const int mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads)
    {
        vector<vector<long long>>graph[n];
        // for(int i=0;i<n;i++)
        // {
        //     graph[roads[i][0]].push_back({roads[i][1],roads[i][2]});
        //     graph[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        // }
        for(vector<int> a:roads){
            ll u = a[0];
            ll v = a[1];
            ll wt = a[2];
            graph[u].push_back({v,wt});
            graph[v].push_back({u,wt});
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
           
            for(auto arr : graph[prev]){
                ll distt = dist + arr[1];
                ll next = arr[0];
                if(dis[next]>distt)
                {
                   
                    dis[next]=distt;
                    pq.push({dis[next],next});
                     ways[next]=ways[prev];
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