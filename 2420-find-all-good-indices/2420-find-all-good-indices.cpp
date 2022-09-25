class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) 
    {
        int n=nums.size();
      vector<int>inc(n),dec(n);
        vector<int>ans;
        inc[n-1]=1;dec[0]=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]>=nums[i])
            {
                dec[i]=dec[i-1]+1;
            } 
            else
                dec[i]=1;
        }
        for(int i=n-1;i>0;i--)
        {
            if(nums[i]>=nums[i-1])
            {
                inc[i-1]=inc[i]+1;
            } 
             else
                inc[i-1]=1;
        }
        for(int i=1;i<n-1;i++)
        {
            if(inc[i+1]>=k&&dec[i-1]>=k)
            {
             ans.push_back(i);   
            }
        }
        return ans;
    }
};