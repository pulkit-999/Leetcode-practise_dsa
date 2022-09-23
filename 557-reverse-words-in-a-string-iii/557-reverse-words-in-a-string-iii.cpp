class Solution {
public:
    string reverseWords(string s)
    {
     string k="";
        s=s+".";
        string w="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=' ' && s[i]!='.')
            {
                w=s[i]+w;
            }
            else if(s[i]=='.')
            {
                k=k+w;
                w="";
            }
            else
            {
                k=k+w+" ";
                w="";
            }
            
        }
        return k;
    }
};