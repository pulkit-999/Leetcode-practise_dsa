class Solution {
public:
    bool check(vector<vector<int>>& heights,int i,int j,int m,int n)
    {
        if(i<0||i>=m ||j<0||j>=n )
            return false;
        return true;
    }
    
    void dfs(vector<vector<int>>& heights,vector<vector<int>>&f,int i,int j,int m ,int n)
    {
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,-1,1};
        if(!f[i][j])
        {
        f[i][j]=1;
        for(int k=0;k<4;k++)
        {
            int x=dx[k]+i;
            int y=dy[k]+j;
            if(check(heights,x,y,m,n))
            {
                    if(heights[x][y]>=heights[i][j])
                         dfs(heights,f,x,y,m,n);
                        
                }
        }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        vector<vector<int>>ans;
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>>f1(m,vector<int>(n,0));
        vector<vector<int>>f2(m,vector<int>(n,0));
        
        
        for(int i=0;i<m;i++)
        {
            dfs(heights,f1,i,0,m,n);
            dfs(heights,f2,i,n-1,m,n);
        }
        for(int j=0;j<n;j++)
        {
            dfs(heights,f1,0,j,m,n);
            dfs(heights,f2,m-1,j,m,n);
        }   
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                
                if(f1[i][j]&&f2[i][j])
                {
              
                    ans.push_back({i,j});
                }
            }
        }
        
        return ans;
        
    }
};