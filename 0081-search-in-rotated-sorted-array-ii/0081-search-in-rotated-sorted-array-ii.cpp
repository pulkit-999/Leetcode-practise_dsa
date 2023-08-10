class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        int n=nums.size();
        int ind=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
            return 1;
         else if(nums[mid]<nums[high])
         {
             if(nums[mid]<target && target<=nums[high])
             low=mid+1;
             else 
             high=mid-1;
         } 
         else if(nums[mid]>nums[high])
         {
             if(nums[mid]>target && target>=nums[low])
               high=mid-1;
             else 
           low=mid+1;
         } 
         else high--;
        }
        return 0;
    }
};