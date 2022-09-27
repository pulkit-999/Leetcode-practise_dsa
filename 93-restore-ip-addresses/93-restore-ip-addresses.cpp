class Solution {
public:
    bool isvalid(string st)
    {
        if(st[0]=='0')
            return false;
        int t=stoi(st);
        if(t>255)
            return false;
        return true;
    }
    
   void help(int i,int count,string &s,string ans,vector<string>&res)
    {
        if(i==s.size() ||count==4)
        {
            if(i==s.size() && count==4)
                res.push_back(ans.substr(0,ans.size()-1));
            return;
        }
        help(i+1,count+1,s,ans+s[i]+".",res);
            if(i+2<=s.size() && isvalid(s.substr(i,2)))
        help(i+2,count+1,s,ans+s.substr(i,2)+".",res);
                if(i+3<=s.size() && isvalid(s.substr(i,3)))
        help(i+3,count+1,s,ans+s.substr(i,3)+".",res);
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string>res;
        help(0,0,s,"",res);
        return res;
    }
};