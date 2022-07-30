class Solution {
public:
    int firstMissingPositive(vector<int>& nums)
    {
        int k=1;
        set<int>s;
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }
 //       sort(nums.begin(),nums.end());
        for(auto x:s)
        {
            if(x>0)
            {
                if(x==k)
                    k++;
                else 
                    return k;
            }
        }
        return k;
        
    }
};