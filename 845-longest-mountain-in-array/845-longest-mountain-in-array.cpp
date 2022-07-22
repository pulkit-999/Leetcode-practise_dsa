class Solution {
public:
    int longestMountain(vector<int>& arr)
    {
     int res=0;
        int n=arr.size();
        int i;
        for( i=1;i<arr.size();i++)
        {
            int count=1;
            bool flag=false;
            int j=i;
            while(j<n && arr[j-1]<arr[j])
            {
                j++;
                count++;
            }
            while(j<n &&i!=j && arr[j-1]>arr[j])
            {
                j++;
                count++;
                flag=true;
            }
            if(i!=j&&count>2&&flag)
            {
                res=max(res,count);
                j--;
            }
            i=j;
        }
        if(arr.size()==2)
            return 0;
           return res;
    }
    
};