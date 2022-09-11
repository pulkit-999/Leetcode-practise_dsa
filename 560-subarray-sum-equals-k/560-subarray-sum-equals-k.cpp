class Solution { 
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        long long i=0,j=0;
        int c=0;
        long long sum=0;
        
        
        unordered_map<int,int>m;
        if(nums.size()==1)
        {
            if(nums[0]!=k)
                return 0;
            else return 1;
        }
        while(j<nums.size())
        {
            sum+=nums[j];
            if (sum==k)
            {
                c++;
            }
           if(m.find(sum-k)!=m.end())
           
                c+=m[sum-k];
                m[sum]++;
            
            j++;
        }
        return c;
    }
};