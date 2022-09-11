class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {
        int count=0;
        int i=0;int j=0;
        int prod=1;
        while(j<nums.size())
        {
            prod=prod*nums[j];
            // if(prod<k)
            // {
            //     j++;
            //     //continue;
            // }
          
            while(prod>=k&&i<=j)
            {
                prod=prod/nums[i];
                i++;
            }
                count+=j-i+1;
            j++;
        }
        return count;
    }
};