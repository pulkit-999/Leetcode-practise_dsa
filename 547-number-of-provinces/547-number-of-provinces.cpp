class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        unordered_set<int>vis;
        int n=isConnected.size();
        deque<int>q;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(vis.find(i)!=vis.end())
                continue;
            count++;
            vis.insert(i);
            q.push_front(i);
            while(!q.empty())
            {
                
            int el=q.back();
                q.pop_back();
            for(int j=0;j<n;j++)
            {
                if(isConnected[el][j]&&vis.find(j)==vis.end())
                {
                    vis.insert(j);
                    q.push_front(j);
                }
            }
        }
    }
        return count;
    }
};