class Solution {
public:
    int find(int a,int par[])
    {
        if(a==par[a])
            return a;
        else
           return  par[a]=find(par[a],par);
    }
    bool equationsPossible(vector<string>& equations)
    {

       int par[26];
        for(int i=0;i<26;i++)
        {
            par[i]=i;
        }
        for(auto x:equations)
        {
            if(x[1]=='=')
            {
                par[find(x[0]-'a',par)]=find(x[3]-'a',par);
            }
        }
        for(auto x:equations)
        {
            if(x[1]=='!' && find(x[0]-'a',par)==find(par[x[3]-'a'],par))
            
                return false;
        }
            return true;
        
    
    
    }
};