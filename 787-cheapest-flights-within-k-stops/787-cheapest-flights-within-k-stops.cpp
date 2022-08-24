class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<int>dis(n,INT_MAX);
        vector<pair<int,int>>graph[n];
        int t=0;
        for(int i=0;i<flights.size();i++)
        {
            graph[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        pq.push({0,{0,src}});
        dis[src]=0;
        
        while(!pq.empty())
        {
            int prev=pq.top().second.second;
            int dist=pq.top().second.first;
            int stops=pq.top().first;
             pq.pop();
             
            if (stops>k)
                    continue;
            for(auto it: graph[prev])
            {
               
                int next=it.first;
                int distt=it.second+dist;
                if(dis[next]>distt)
                {
                    dis[next]=distt;
                    pq.push({stops+1,{dis[next],next}});
                }
            }
        }
        return (dis[dst]==INT_MAX)?-1:dis[dst];
    }
};