class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) 
    {
    
        long long int ans,sum=0;
        ans=1e9;
        deque<pair<long long int,long long int>>q;
   for(long long int i=0;i<nums.size();i++)
   {
    sum+=nums[i];
       if(sum>=k)
           ans=min(ans,i+1);
       while(!q.empty() && sum-q.front().first>=k)
       {
           //sum=sum-q.front().first;
               ans=min(ans,i-q.front().second);
           q.pop_front();
       }
       while(!q.empty() && sum<q.back().first)
       {
           q.pop_back();
        }
       q.push_back({sum,i});
   }
        if(ans==1e9 )
            return -1;
        return ans;
    }
};