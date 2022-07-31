class Solution {
public:
    void solve(vector<int>& nums,vector<int>& ds,int maxi,int ind,int &count)
    {
        if(ind==nums.size())
        {
            int cur=0;
            for(auto x:ds)
            {
                cur=cur|x;
            }
            if(cur==maxi)
            {
                count++;
            }
            return;
        }
        ds.push_back(nums[ind]);
        solve(nums,ds,maxi,ind+1,count);
             ds.pop_back();
        solve(nums,ds,maxi,ind+1,count);
    }
    int countMaxOrSubsets(vector<int>& nums) 
    {
        int maxi=0;
        int count=0;
        vector<int>ds;
        for(auto x:nums)
        {
            maxi=maxi|x;
        }
     solve(nums,ds,maxi,0,count);
        return count;
    }
};