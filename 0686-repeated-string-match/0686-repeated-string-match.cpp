class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int lena=a.size();
        int lenb=b.size();
        int n=lenb/lena;
        int cnt=n;
        string fk="";
        while(cnt--)
        {
            fk+=a;    
        }
        if(fk.find(b)!=string::npos)
        return n;
        fk+=a;
        if(fk.find(b)!=string::npos)
        return n+1;
        fk+=a;
        if(fk.find(b)!=string::npos)
        return n+2;
        return -1;
     }
};