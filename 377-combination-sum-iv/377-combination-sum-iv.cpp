class Solution {
public:
   
    int solve(vector<int>& nums,vector<vector<int>>& dp, int &target, int index ,int sum){
        int n=nums.size(), count=0;
        if(index>=n || sum>target)
            return 0;
        if(dp[index][sum]!=-1)
            return dp[index][sum];
        if(sum==target)
            return dp[index][sum]=1;
        for(int i=index; i<n; i++)
            count+=solve(nums,dp, target, index, sum+nums[i]);
        return dp[index][sum]=count;
    }
    int combinationSum4(vector<int>& nums, int target) {
         vector<vector<int>> dp(nums.size(),vector<int>(target+1,-1));
        return solve(nums,dp,target,0,0);
    }
};