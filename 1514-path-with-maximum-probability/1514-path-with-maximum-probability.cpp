class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) 
    {
        priority_queue<pair<double,int>>pq;
        vector<double>dis(n,0);
        pq.push({1.0,start});
        int t=0;
        vector<pair<double,double>>graph[n];
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back({edges[i][1],succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        while(!pq.empty())
        {
            int prev=pq.top().second;
            double dist=pq.top().first;
            pq.pop();
            for(auto it:graph[prev] )
            {
                int next=it.first;
                // if(next==end)
                //     t=1;
                double distt=it.second*dist;
                if(dis[next]<distt)
                {
                    dis[next]=distt;
                    pq.push({dis[next],next});
                }
            }
        }
            return dis[end];
    }
};