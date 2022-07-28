class Solution {
public:
    int findMin(vector<int>& nums) 
    {
     int lo=0;
        int hi=nums.size()-1;
        int n=nums.size();
        int mid=0;
        if(nums[0] < nums[n-1])
        return nums[0];
        int N = nums.size();
       
        if(nums[hi] >= nums[0]) return nums[0];
        while(lo<=hi) {
             mid = lo + (hi-lo) / 2;
            if(nums[mid] <= nums[(mid+N-1) % N]) return nums[mid];
            else if(nums[mid] >= nums[0]) lo = mid+1;
            else hi = mid-1;
        }
        return 0;
    }
};