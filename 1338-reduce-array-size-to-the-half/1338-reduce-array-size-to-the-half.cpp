class Solution {
public:
    int minSetSize(vector<int>& arr)
    {
        unordered_map<int,int>m;
        set<int>s;
        int c=0;
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<arr.size();i++)
        {
            m[arr[i]]++;
        }
        for(auto x:m)
        {
            pq.push({x.second,x.first});
        }
        while(!pq.empty())
        {
            int j=pq.top().first; 
            int k=pq.top().second; 
            while(j--)
            {
            s.insert(k);
                c++;
            }
            pq.pop();
            if(c>=(arr.size()/2))
                break;
        }
        return s.size();
        }
};