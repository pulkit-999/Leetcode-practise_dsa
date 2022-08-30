class Solution {
public:
    void solve(int opening,int closing,vector<string>&ans,vector<string>&ds)
    {
        
        if(opening==-1 or closing==-1 or closing <opening )
            return ;
        if(opening==0 && closing ==0)
        {
            string s="";
            for(auto x:ds)
                s=s+x;
            ans.push_back(s);
            return;
        }
        else{
        ds.push_back("(");
        solve(opening-1,closing,ans,ds);
        ds.pop_back();
        ds.push_back(")");
        solve(opening,closing-1,ans,ds);
        ds.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        vector<string>ds;
        if(n==1)
            return ans={"()"};
        solve(n,n,ans,ds);
        return ans;
    }
};