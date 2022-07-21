class Solution {
public:
    string minWindow(string s, string t)
    {
        unordered_map<char,int>m;
        for(int i=0;i<t.size();i++)
        {
            m[t[i]]++;
        }
        
        int i=0,j=0;
        int count=m.size();
        int n=s.size();
        int k=n+1;
        int start=0;
        while(j<n)
        {
            if(m.find(s[j])!=m.end())
            {
                m[s[j]]--;
                if(m[s[j]]==0)
                    count--;
            }
           
            if(count>0)
            {
                j++;
            }
            else if(count==0)
            {
                
                    if(k>j-i+1)
                    {
                        k=j-i+1;
                        start=i;
                }
            
            while(count==0)
            {   
            if(m.find(s[i])==m.end())
            {
                i++;
                if(k>j-i+1)
                {
                    k=j-i+1;
                    start=i;
                }
            }
            else
                {
                        m[s[i]]++;
                if(m[s[i]]>0)
                {
                      i++;
                    count++;
                }
                else
                {
                      i++;
                
                   if(k>j-i+1)
                   {
                        
                       k=j-i+1;
                       start=i;
                   }
                    
                }
                        
                }
            }
                 j++;
        }
           
    }
        //cout<<start<<" "<<k;
        if(s.size()<t.size())
          return "";
        if(k==n+1)
            return "";
        string ans= s.substr(start,k);
        return ans;
    }
    
};