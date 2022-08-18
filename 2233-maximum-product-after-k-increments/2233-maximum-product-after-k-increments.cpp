class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) 
    {
        long int res=1;
     priority_queue<int,vector<int>,greater<int>>pq;
       for(int i=0;i<nums.size();i++)
           pq.push(nums[i]);
        while(k--)
        {
            int d=pq.top();
            d=d+1;
            pq.pop();
            pq.push(d);
        }
        while(!pq.empty())
        {
            int t=pq.top();
            pq.pop();
            res=(res*t)%1000000007;
        }
        return res;
    }
};