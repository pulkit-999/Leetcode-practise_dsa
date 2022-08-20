class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
      deque<int>q;
        vector<int>graph[n];
        unordered_set<int>vis;
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        q.push_front(source);
        vis.insert(source);
        while(!q.empty())
        {
            int el=q.back();
            q.pop_back();
            if(el==destination)
                return true;
              
            for(int i=0;i<graph[el].size();i++)
            {
                if(vis.find(graph[el][i])==vis.end() )
                {
                    vis.insert(graph[el][i]);
                    q.push_front(graph[el][i]);
                }
            }
            
        }
        return false;
    }
};