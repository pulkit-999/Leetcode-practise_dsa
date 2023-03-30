//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

vector<int> square(int arr[], int n);


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n+1];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        vector<int> ans;
        ans = square(arr, n);
        for(int i:ans)
            cout << i << " ";
        cout << endl;
        
    }
    return 0;
}

// } Driver Code Ends


vector<int> square(int arr[], int n)
{
    // Complete the function



    unordered_map<int,int>m;
    for(int i=0;i<n;i++)
    {
          m[arr[i]]++;
    }
    priority_queue<pair<int,int>>pq;
    int ans=0,c=0;
    for(auto &x:m)
    {
        if(x.second>=4)
      pq.push({x.first,x.second});
    }
    // while(pq.size())
    // {
    //     cout<<pq.top().first<<" "<<pq.top().second<<" ";
    //     pq.pop();
    // }
    while(pq.size())
    {
        auto k=pq.top().second;
        auto p=pq.top().first;
        if(k<4)
        m.erase(p);
        pq.pop();
        
        if(k>=4 and ans<p)
        {
            ans=p;
            k=k-4;
            if(k>=4)
            pq.push({p,k});
            c=1;
        }
        else if (k>=4 and ans==p)
        {
            k=k-4;
            if(k>=4)
            pq.push({p,k});
            c++;
        }

        if(ans>p)
        break;
        
    }
    if(c==0)
    return {-1};
    return {ans*ans,c};
}