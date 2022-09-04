class Solution {
public:
    long long minimumReplacement(vector<int>& nums) 
    {
        int n=nums.size();
    int x=nums[n-1];int f=0;
       long long ans=0;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<=x)
                x=nums[i];
            else
            {
                f=(nums[i]+x-1)/x;
                ans+=f-1;
                x=nums[i]/f;
            }
        }
        return ans;
    }
};