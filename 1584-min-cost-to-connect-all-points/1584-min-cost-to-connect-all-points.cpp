class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points)
    {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
      for(int i=0;i<points.size();i++)
      {
      for(int j=i+1;j<points.size();j++)
      {
        int dis=(abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]));    
          pq.push({dis,{i,j}});
      }
      }
        int n=points.size();
vector<int>par(n);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            par[i]=i;
        }
        while(n>1)
        {
            int d=pq.top().first;
            int a=pq.top().second.first;
                int b=pq.top().second.second;
            pq.pop();
            int node_a=par[a];
            int node_b=par[b];
            while(node_a!=par[node_a])
                node_a=par[node_a];
             while(node_b!=par[node_b])
                node_b=par[node_b];
            if(node_a!=node_b)
            {
                n--;
                par[node_a]=node_b;
                sum+=d;
            }
            
                
        }
        return sum;
    }
};