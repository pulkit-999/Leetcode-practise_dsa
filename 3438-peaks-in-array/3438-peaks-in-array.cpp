class Solution {
public:
    int sgt[4*100000+1];
    bool peaks_check(long long i,vector<int>& nums)
    {
       return(i>0 and i<nums.size()-1 and nums[i]>nums[i-1] and nums[i+1]<nums[i]);
       
    }
    void build(int ind,int low,int high,vector<int>& nums)
    {
        if(low==high)
        {
            sgt[ind]=peaks_check(low,nums)?1:0;
        return;
        }
       long long mid=low+(high-low)/2;
        build(2*ind+1,low,mid,nums);
         build(2*ind+2,mid+1,high,nums);
         sgt[ind]=sgt[2*ind+1]+sgt[2*ind+2];
        
    }

    void update(int ind,int low,int high,int i,int val,vector<int>& nums)
    {
        if(low==high)
         sgt[ind]=peaks_check(low,nums)?1:0;
         else{

        long long mid=low+(high-low)/2;
        if(low<=i and i<=mid)
        {
            update(2*ind+1,low,mid,i,val,nums);
        }
        else
        update(2*ind+2,mid+1,high,i,val,nums);
        sgt[ind]=sgt[2*ind+1]+sgt[2*ind+2];
         }
    }
    long long query(int ind,int low,int high,int left,int right)
    {
        if(right<low or high <left )
        return 0;
        else if(low>=left and high<=right)
        return sgt[ind];
        long long mid=low+(high-low)/2;
       long long leftt= query(2*ind+1,low,mid,left,right);
        long long rightt =query(2*ind+2,mid+1,high,left,right);
        return leftt+rightt;
    }

    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>ans;
        int n=nums.size();
        build(0,0,nums.size()-1,nums);
        for(auto &x:queries)
        {
            if(x[0]==1)
            {
                int left=x[1];
                int right=x[2];
                if(right-left+1<3)
                {
                    ans.push_back(0);
                    continue;
                }
                int peaks=query(0,0,nums.size()-1,left+1,right-1);
                ans.push_back(peaks);
            }
            else{
                int index=x[1];
                int val=x[2];
                nums[index] = val;
                
                for(int i = max(1, index-1); i<=min(n-2, index+1);i++){
                   update(0,0,nums.size()-1,i,val,nums);
                }
                
                
            }
        }
        return ans;
    }
};