class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>>ans;
        
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++)
        {
            if(i==0||nums[i]!=nums[i-1])
            {
                int low=i+1;
                int high=nums.size()-1;
                int sum=0-nums[i];
                while(low<high)
                {
                    vector<int>res;
                    if(nums[low]+nums[high]==sum)
                    {
                        res.push_back(nums[i]);
                        res.push_back(nums[low]);
                        res.push_back(nums[high]);
                        ans.push_back(res);
                    
                    while(low<high  &&nums[low]==nums[low+1])low++;
                        while(low<high &&nums[high]==nums[high-1])high--;
                    low++;
                    high--;
                    }
                    else if(nums[low]+nums[high]<sum)
                    {
                        low++;
                    }
                    else{
                        high--;
                    }
                }
            }
        }
        
        return ans;
    }
};