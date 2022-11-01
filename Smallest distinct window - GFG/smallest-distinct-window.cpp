//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        string s=str;
         set<char>st;
        unordered_map<char,int>m;
        for(int i=0;i<s.length();i++)
        {
            st.insert(s[i]);
        }
        int n=st.size();
        int j=0;
        int ans=INT_MAX;
        int c=0;
        int start=0;
        for(int i=0;i<s.length();i++)
        {
            m[s[i]]++;
            if(m[s[i]]==1)
            c++;
            if(c==n)
            {
                while(m[s[start]]>1)
                {
                if(m[s[start]]>1)
                {
                    m[s[start]]--;
                start++;
            }
                }
            
            int curr=i-start+1;
            
            if(curr<ans)
            {
                ans=curr;
            }
            }
        }
        
     
return ans;
} 
    
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends