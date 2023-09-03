class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int j=0;
        unordered_map<char,int>a,b,c,d;
        for(int i=0;i<s1.size();i++)
        {
            if(i&1)
            {
                c[s1[i]]++;
                    d[s2[i]]++;
            }
            else
            {
                 a[s1[i]]++;
                    b[s2[i]]++;
            }
        }
        return (a==b and c==d);
        
    }
};