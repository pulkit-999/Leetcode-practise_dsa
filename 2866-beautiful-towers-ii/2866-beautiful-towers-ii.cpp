class Solution {
public:
  void pse(vector<int>& a,vector<int>&left)
  {
    stack<int>s;
    for(int i=0;i<a.size();i++)
    {
        while(s.size() and a[s.top()]>=a[i])
        {
            s.pop();
        }
        if(s.size())
        {
            left[i]=s.top();
        }
        else
        left[i]=-1;
        s.push(i);
    }
  }

  void nse(vector<int>& a,vector<int>&right)
  {
     stack<int>s;
    for(int i=a.size()-1;i>=0;i--)
    {
        while(s.size() and a[s.top()]>=a[i])
        {
            s.pop();
        }
        if(s.size())
        {
            right[i]=s.top();
        }
        else
        right[i]=a.size();
        s.push(i);
    }
  }
    long long maximumSumOfHeights(vector<int>& a) {
        int n=a.size();
        long long ans=0;
        vector<int>temp=a;
       vector<int>left(n,0),right(n,0);
       pse(a,left);
       vector<long long>prefix(n,0),suffix(n,0);
       prefix[0]=a[0];
       for(int i=1;i<n;i++)
       {
        int x=left[i];
        long long calc=1LL*(i-x)*a[i];
        int y=x-1;
        if(x==-1)
        prefix[i]=calc;
        if(x>=0)
        prefix[i]=prefix[x]+calc;
       }
       nse(a,right);

         for(int i=n-1;i>=0;i--)
       {
        int x=right[i];
        if(x==n)
        suffix[i]=1LL*(n-i)*a[i];
        else
        suffix[i]=1LL*suffix[x]+1LL*(x-i)*a[i];
       }

       for(int i=0;i<n;i++)
       ans=max(1LL*prefix[i]+suffix[i]-a[i],ans);
       return ans;
       
    }

};