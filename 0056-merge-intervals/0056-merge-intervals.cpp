class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        priority_queue<pair<int,int>>pq;
        pq.push({intervals[0][1],intervals[0][0]});
        for(int i=1;i<intervals.size();i++)
        {
            if(pq.top().first<intervals[i][0])
            {
            pq.push({intervals[i][1],intervals[i][0]});
            }
            else if(intervals[i][0]<=pq.top().first)
            {
                int a=pq.top().first;
                int b=pq.top().second;
                pq.pop();
                pq.push({max(a,intervals[i][1]),b});
            }
        }
        while(pq.size())
        {
            int a=pq.top().first;
                int b=pq.top().second;
                vector<int>ss;
                ss.push_back(b);
                ss.push_back(a);
                ans.push_back(ss);
                pq.pop();
        }
        return ans;
    }
};