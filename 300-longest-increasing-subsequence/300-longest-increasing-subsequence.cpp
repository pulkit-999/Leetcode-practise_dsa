class Solution {
   
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>res;
    res.push_back(nums[0]);
    int len=1;int ind=0;
  for(int i=1;i<nums.size();i++)
  {
      if(nums[i]>res.back())
      {
         res.push_back(nums[i]);
          len++;
      }
      else
      {
          ind=lower_bound(res.begin(),res.end(),nums[i])-res.begin();
          res[ind]=nums[i];
      }
  }
    return len;
    }
};