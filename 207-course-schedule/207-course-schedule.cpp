class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        deque<int>q;
        vector<int>indegree(numCourses,0);
vector<int>graph[numCourses];
        int count=0;
        if(prerequisites.size()==0)
            return true;
        for(int i=0;i<prerequisites.size();i++)
        {
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
            indegree[prerequisites[i][1]]++;
        }
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            q.push_front(i);
        }
        
        count=q.size();
        while(!q.empty())
        {
            int el=q.back();
            q.pop_back();
            for(auto y:graph[el])
            {
                indegree[y]--;
                if(indegree[y]==0)
                {
                    q.push_front(y);
                    count++;
                }
            }
        }
        
            return(count==numCourses);
    }

};