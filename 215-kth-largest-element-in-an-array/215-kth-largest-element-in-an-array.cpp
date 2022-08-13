class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
    int n = nums.size();
    while(k > 0){
        k--;
        n--;
    }
    return nums[n];
    }
};