class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        vector<int>lps(s.size());
        for(int i=1;i<lps.size();i++)
        {
            int j=lps[i-1];
            while(j>0 and s[i]!=s[j])
            j=lps[j-1];
            if(s[i]==s[j])
            j++;
            lps[i]=j;
        }
        int i=0,j=0;
        while(i<s.size())
        {
            if(s[i]==s[j])
            {
                i++;
                j++;
            }
            if(j==s.size())
            {
                j=lps[j-1];
            }
            else if(s[i]!=s[j])
            {
                if(j==0)
                i++;
                else
                j=lps[j-1];
            }
        }
        return lps[s.size()-1]&&lps[s.size()-1]%(s.size()-lps[s.size()-1])==0;
    }
};