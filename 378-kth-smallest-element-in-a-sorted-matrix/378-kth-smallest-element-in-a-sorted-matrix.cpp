class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        vector<int>v;
        for(auto x:matrix)
        {
            for(auto y:x)
                v.push_back(y);
        }
        sort(v.begin(),v.end());
        int ans=v[k-1];
        return ans;
    }
};