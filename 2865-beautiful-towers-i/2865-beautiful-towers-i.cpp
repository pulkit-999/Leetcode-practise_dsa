class Solution {
public:
    void solve(vector<int>& a,vector<long long>&left)
    {
        for(int i=1;i<a.size();i++)
        {
            long long cnt=0;
            if(a[i-1]<=a[i])
            {
                left[i]=left[i-1];
            continue;
            }
            else
            {
                for(int j=0;j<i;j++)
                {
                    if(a[j]>a[i])
                    {
                    cnt+=(long long)(a[j]-a[i]);
                    a[j]=a[i];
                }
                }
                left[i]=left[i-1]+cnt;
            }
            
        }
    }
    long long maximumSumOfHeights(vector<int>& a) {
        int n=a.size();
        long long ans=1e18;
        long long sum=0;
        for(auto x:a)
        sum+=x;
         vector<int>temp=a;
        vector<long long>left(n,0),right(n,0);
        solve(a,left);
       
        reverse(temp.begin(),temp.end());
        solve(temp,right);
    reverse(right.begin(),right.end());
        for(int i=0;i<n;i++)
        {
            cout<<left[i]<<" "<<right[i]<<endl;
            ans=min((long long)left[i]+right[i],ans);
        }
       
       return sum-ans;
    }
};