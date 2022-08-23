class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
    {
        vector<pair<int,int>>graph[n];
       int mini=1e9;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        priority_queue<pair<int,int>>q;
         q.push({0,1e9});
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            graph[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        for(int i=0;i<n;i++)
        {
             vector<int>dis(n+1,INT_MAX);
            pq.push({0,i});
            dis[i]=0;
            int count=0;
            while(!pq.empty())
            {
                int prev=pq.top().second;
                int dist=pq.top().first;
                pq.pop();
                for(auto it:graph[prev])
                {
                    int next=it.first;
                    int distt=dist+it.second;
                    if(dis[next]>distt )
                    {
                        
                        dis[next]=distt;
                        pq.push({dis[next],next});
                    }
                }
            }
            for(int i=0;i<n;i++)
            {
                if(dis[i]!=INT_MAX && dis[i]<=distanceThreshold)
                {
                    count++;
                }
            }
            if(mini>=count)
            {
                q.pop();
                mini=count;
            q.push({i,mini});
            }
        }
        return q.top().first;
    }
};