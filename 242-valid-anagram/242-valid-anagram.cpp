class Solution {
public:
    bool isAnagram(string s, string t) 
    {
      int hash[123]={0},hash1[123]={0},i;
        for(i=0;i<s.size();i++)
        {
            hash[s[i]]++;
        }
        for(i=0;i<t.size();i++)
        {
            hash1[t[i]]++;
        }
        for(i=97;i<=122;i++)
        {
            if(hash[i]!=hash1[i])
            {
                return false;
            }
        }
        return true;
        
    }
};