class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        priority_queue<pair<int, int> > pq;
        vector<int>ans;
        for(auto x:m)
        {
            pq.push({x.second,x.first});
        }
        while(k--)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};