class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        multiset<int>m;
        int i=0;
        for(auto &x:nums)
        {
            m.insert(x);
        }
        for(auto &y:m)
        {
            
            nums[i++]=y;
        }
    }
};