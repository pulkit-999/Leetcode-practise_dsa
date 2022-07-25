class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) 
    {
        set<int>s;
        for(auto x:nums)
        {
            s.insert(x);
        }
    vector<int>ans;
        for(auto f:s)
            ans.push_back(f);
        vector<int>set_bit(32,0);
        for(int i=0;i<ans.size();i++)
        {
         set_bit[__builtin_popcount(ans[i])]++;
                }
        long long res=0;
        for(int i=0;i<32;i++)
        {
            for(int j=0;j<32;j++)
            {
                if(i+j>=k)
                {
                    res+=set_bit[i]*set_bit[j];
                }
            }
        }
        
        
        return res;;
    }
};