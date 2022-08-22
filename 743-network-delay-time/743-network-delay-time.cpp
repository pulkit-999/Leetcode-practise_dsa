class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
    vector<pair<int,int>>graph[n+1];
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dis(n+1,INT_MAX);
        for(int i=0;i<times.size();i++)
        {
            graph[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        int sum=0;
        dis[k]=0;
        pq.push({0,k});
        while(!pq.empty())
        {
            int dist=pq.top().first;
            int prev=pq.top().second;
            pq.pop();
            for(auto it:graph[prev])
            {
                int next=it.first;
                int distt=dist+it.second;
                if(dis[next]>distt)
                {
                    dis[next]=distt;
                    pq.push({dis[next],next});
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(dis[i]==INT_MAX)
                return -1;
            else
                sum=max(sum,dis[i]);
        }
        return sum;
    }
};