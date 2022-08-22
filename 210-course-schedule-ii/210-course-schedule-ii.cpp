class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
     queue<int>q;
        vector<int>graph[numCourses];
        vector<int>ans;
        vector<int>indegree(numCourses,0);
        for(int i=0;i<prerequisites.size();i++)
        {
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
            indegree[prerequisites[i][1]]++;
        }
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
             int el=q.front();
            ans.insert(ans.begin(),el);
            q.pop();
            for(auto y:graph[el])
            {
                indegree[y]--;
                if(indegree[y]==0)
                    q.push(y);
            }
        }
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]!=0)
            {
                ans.clear();
                return ans;
                }
        }
        //reverse(ans.begin(),ans.end());
        return ans;
    }
};