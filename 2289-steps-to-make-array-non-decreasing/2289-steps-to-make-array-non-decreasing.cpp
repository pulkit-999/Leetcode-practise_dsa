class Solution {
public:
    int totalSteps(vector<int>& nums) {
        stack<pair<int,int>>s;
        int ans=0;
        int cnt=0;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(s.size()==0)
            {
                s.push({nums[i],0});
            }
            else{
                while(s.size() and s.top().first<nums[i])
                {
                         cnt=max(cnt+1,s.top().second);
                    s.pop();
                }
                s.push({nums[i],cnt});
                ans=max(ans,cnt);
                cnt=0;
            }
        }
        return ans;
    }
    
};