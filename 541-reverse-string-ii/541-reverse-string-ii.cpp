class Solution {
public:
    string reverseStr(string s, int k) 
    {
        string ans="";
        int rem=s.size();
        int n=s.size();
     while(rem>0)
     {
            int j=n-rem;
         if(rem>=k)
         {
             reverse(s.begin()+j,s.begin()+j+k);
             rem=rem-2*k;
             
         }
         else if(rem<k)
         {
             reverse(s.begin()+j,s.end());
             rem=0;
         }
        }
        return s;
        
    }
};