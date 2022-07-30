class Solution {
public:
    int firstMissingPositive(vector<int>& nums)
    {
       unordered_map<int,int> m;
    int maxi =0;
    for(auto x:nums)
    {
        maxi= max(maxi,x);
        m[x]++;
    }
    for(int i=1;i<=maxi;i++)
    {
        if(m[i]==0)
        {
            return i;
        }
    }
    return maxi+1;
    
}
};